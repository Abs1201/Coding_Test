#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=2e5;
int n, m, p[mxN];
vector<int> adj[mxN], ans;

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(p, -1, 4*n);
    queue<int> qu;
    qu.push(0);
    while(qu.size()){
        int u=qu.front();
        qu.pop();
        for(int v: adj[u]){
            if(p[v]<0){
                p[v]=u;
                qu.push(v);
            }
        }
    }
    if(p[n-1]<0){
        cout << "IMPOSSIBLE";
    }
    else{
        int u=n-1;
        ans.push_back(u);
        while(p[u]){
            ans.push_back(p[u]);
            u=p[u];
        }
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        
        cout << ans.size() << endl;
        for(int v: ans){
            cout << v+1 << " ";
        }
    }
    
    return 0;
}