#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=2e5;
int n ,m;
vector<int> adj[mxN], ans;
bool vis[mxN];

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[0]=1;
    ans.push_back(0);


    for(int i=0; i<ans.size(); i++){
        cout << ans[0]+1 << " " << ans[i]+1;
    }

    return 0;
}