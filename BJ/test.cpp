#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s[100];
int p[100][100], ans[100][100];
int w, h;
int si, sj, ti, tj;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1}; // u l d r

bool valid(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w && s[i][j] != '*';
}

int main(void) {
    cin >> w >> h;
    bool foundFirst = false;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'C') {
                if (!foundFirst) {
                    si = i, sj = j;
                    foundFirst = true;
                } else {
                    ti = i, tj = j;
                }
            }
        }
    }

    memset(p, -1, sizeof(p));
    memset(ans, 0x3f, sizeof(ans));

    bool vis[100][100] = {0};
    queue<tuple<int, int, int, int>> qu; // (x, y, 거울 설치 횟수, 방향)
    for (int i = 0; i < 4; i++) {
        qu.push({si, sj, 0, i});
    }
    ans[si][sj] = 0;

    while (!qu.empty()) {
        auto [x, y, mirrors, dir] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + di[i], ny = y + dj[i];
            if (valid(nx, ny)) {
                int newMirrors = mirrors + (i != dir);
                if (newMirrors < ans[nx][ny]) {
                    ans[nx][ny] = newMirrors;
                    qu.push({nx, ny, newMirrors, i});
                }
            }
        }
    }

    cout << ans[ti][tj] << endl;

    return 0;
}
