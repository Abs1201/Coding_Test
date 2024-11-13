
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
string board[10];
bool visited[10][10][10][10]; // 방문 배열 [빨간 구슬 x][빨간 구슬 y][파란 구슬 x][파란 구슬 y]
int dx[4] = {-1, 1, 0, 0}; // 상하좌우 이동
int dy[4] = {0, 0, -1, 1};

struct State {
    int rx, ry, bx, by, count;
};

bool move(int &x, int &y, int dx, int dy, int &steps) {
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O') {
        x += dx;
        y += dy;
        steps++;
        if (board[x][y] == 'O') break;
    }
    return board[x][y] == 'O';
}

int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;
    
    while (!q.empty()) {
        auto [rx, ry, bx, by, count] = q.front();
        q.pop();
        
        if (count > 10) return -1;

        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int red_steps = 0, blue_steps = 0;

            bool red_hole = move(nrx, nry, dx[i], dy[i], red_steps);
            bool blue_hole = move(nbx, nby, dx[i], dy[i], blue_steps);

            if (blue_hole) continue; // 파란 구슬이 구멍에 빠지면 실패
            if (red_hole) return count + 1; // 빨간 구슬만 구멍에 빠지면 성공

            // 구슬이 겹치면 이동 횟수를 비교하여 위치 조정
            if (nrx == nbx && nry == nby) {
                if (red_steps > blue_steps) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }

            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, count + 1});
            }
        }
    }
    return -1; // 10번 이내로 성공하지 못하면 -1 반환
}

int main() {
    cin >> n >> m;
    int rx, ry, bx, by;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') rx = i, ry = j;
            if (board[i][j] == 'B') bx = i, by = j;
        }
    }
    
    cout << bfs(rx, ry, bx, by) << endl;
    return 0;
}
