#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=2e5;
int n, m;
vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int u){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[u]){
            dfs(v);
        }
    }
}

int main(void){
    cin >> n >> m;
    for (int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size()-1 << endl;
    for(int i=1; i<ans.size(); i++){
        cout << ans[0]+1 << " " << ans[i]+1 << endl;
    }

    return 0;
}