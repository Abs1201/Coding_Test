#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=2e5;
int n, m;
vector<int> adj[mxN], ans;

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> qu;
    qu.push(0);


    return 0;
}