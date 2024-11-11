#include <bits/stdc++.h>
using namespace std;

const int mxN = 1000;

int t, n, k;
int d[mxN];

int main(void){
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        vector<int> adj[mxN];
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
        }

        vector<int> inDegrees(n, 0);
        for (int i = 0; i < n; i++) {
            for (int a : adj[i]) {
                inDegrees[a]++;
            }
        }

        int W;
        cin >> W;
        W--; // 0부터 시작하는 인덱스로 변환

        queue<int> qu;
        vector<int> time(n, 0);

        for (int i = 0; i < n; i++) {
            if (inDegrees[i] == 0) {
                qu.push(i);
                time[i] = d[i]; // 초기 시간 설정
            }
        }

        while (!qu.empty()) {
            int a = qu.front();
            qu.pop();
            for (int e : adj[a]) {
                inDegrees[e]--;
                time[e] = max(time[e], time[a] + d[e]);
                // d[e]=d[e]+d[a];
                if (inDegrees[e] == 0) {
                    qu.push(e);
                }
            }
        }

        cout << time[W] << endl;
    }
    return 0;
}
