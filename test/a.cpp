#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=2e5;
int n, m;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u, int cu=-1){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size()-1 << endl;
    for(int i=1; i<ans.size(); i++){
        cout << 1 << " " << ans[i]+1 << endl;
    }
    
    return 0;
}