#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, s[mxN];
vector<int> adj[mxN];

void dfs(int u=0){
    s[u]=1;
    for(int v: adj[u]){
        dfs(v);
        s[u]+=s[v];
    }
}

int main(void){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int p;
        cin >> p, --p;
        adj[p].push_back(i);
    }
    dfs();


    return 0;
}