#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=2e5;
int n, m, c[mxN];
vector<int> adj[mxN], ans;

void dfs(int u, int cu=0){
    p[u]=pu;
    vis[u]=1;
    for(int v: adj[v]){
        if(v==pu)
            continue;
        if(vis[v]){
            while(u^v){
                ans.push_back(u);
                u=p[u];
            }
            ans.push_back(v);
            ans.push_back(u);
            cout << ans.size() << "\n";
            for(int a: ans){
                cout << a+1 << " ";
            }
            exit(0);
        }
        else
            dfs(v, u)
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}