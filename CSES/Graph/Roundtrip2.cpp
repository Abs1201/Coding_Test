#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=2e5;
int n, m, p[mxN];
vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int u, int pu=-1){
    vis[u]=1;
    p[u]=pu;
    for(int v: adj[u]){
        if(v==pu) continue;
        if(vis[v]){
            int u2=u;
            while(v^u){
                ans.push_back(u);
                u=p[u];
            }
            ans.push_back(v);
            ans.push_back(u2);
            cout << ans.size() << endl;
            for(int a: ans){
                cout << a+1 << " ";
            }
            exit(0);
        }
        else{
            dfs(v,u);
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
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    cout << "IMPOSSIBLE";
    
    
    return 0;
}