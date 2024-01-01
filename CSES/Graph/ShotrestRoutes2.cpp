#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=500;
int n,m,q;
vector<array<ll, 2>> adj[mxN];
ll d[mxN][mxN];

int main(void){
    cin >> n >> m >> q;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    


    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b, --a, --b;
        if(d[a][b] > 1e8){
            cout << -1 << " ";
            continue;
        }
        cout << d[a][b] << " ";
    }

    return 0;
}