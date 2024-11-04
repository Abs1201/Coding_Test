#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e5;

int n, m, p[mxN];

vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int u, int pu=-1){
    p[u]=pu;
    vis[u]=1;
    for(int v: adj[u]){
        if(v==pu) continue;
        if(vis[v]){
            while(v^u){
                ans.push_back(u);
                u=p[u];
            }
            ans.push_back(v);
            ans.push_back(u);

            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); i++){
                cout << ans[i]+1 << " ";
            }
            exit(0);
        }
        else{
            dfs(v, u);
        }
    }
}

vector<pair<int,int>> adj;
int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(p, -1, sizeof(int)*n);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE";
    

    return 0;
}