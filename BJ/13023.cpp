#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mxN=2000;

int n, m;
vector<int> v[mxN];
bool vis[mxN];

bool dfs(int u, int uv=0){
    vis[u]=1;

    if(uv>=4){
        return 1;
    }
    for(auto& e: v[u]){
        if(!vis[e] && dfs(e, uv+1)){
            return 1;
        }
    }
    vis[u]=0;
    return 0;
}


int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool b=0;
    for(int i=0; i<n; i++){
        memset(vis, 0, sizeof(vis));
        // fill(vis, vis+mxN, 0);
        b = dfs(i);
        if(b) break;
    }
    cout << (b ? 1:0);

    return 0;
}
