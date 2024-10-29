#include <iostream>
using namespace std;

#define ll long long

char s[50][50];

bool e(int a, int b) {
    if (a >= 0 && b >= 0 && a < 50 && b < 50 && s[a][b] == '1') return true;
    return false;
}

void dfs(int a, int b) {
    if (e(a, b)) {
        s[a][b] = '0'; // Mark the visited position with '0'
        dfs(a - 1, b);
        dfs(a + 1, b);
        dfs(a, b - 1);
        dfs(a, b + 1);
    }
}

int main() {
    int T;
    cin >> T;

    int x, y, n;
    for (int i = 0; i < T; i++) {
        int ans = 0;
        cin >> x >> y >> n;

        // Initialize the `s` array with '0'
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {
                s[j][k] = '0';
            }
        }

        // Input positions and set them to '1'
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            s[a][b] = '1';
        }

        // Perform DFS to count connected components
        for (int k = 0; k < 50; k++) {
            for (int l = 0; l < 50; l++) {
                if (e(k, l)) {
                    dfs(k, l);
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
