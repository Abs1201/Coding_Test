//bellman-ford
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2500, mxM=5000;

int n, m;
vector<array<ll, 2>> adj[mxN];
ll d[mxN];

int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c,b});
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            if(d[j] < d[j]+)
        }
    }
    



    return 0;
}