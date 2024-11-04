#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e5, mxM=2e5;
int a, b;
int n, m, p[mxN];

vector<pair<int,int>> adj;
int main(void){
    // cin >> n >> m;
    // for(int i=0; i<3; i++){
    //     cin >> a >> b, --a, --b;
    //     adj[a].push_back(b);
    //     adj[b].push_back(a);
    // }
    adj.push_back({1,3});

    cout << adj[0].first << " " << adj[0].second << endl;



    return 0;
}