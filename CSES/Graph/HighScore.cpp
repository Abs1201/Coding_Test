#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2500, mxM=5000;
ll n, m, ans[mxN];
vector<array<ll, 2>> adj[mxN];
ll d[mxN];

int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c,b});
    }    
    memset(d, 0xc0, sizeof(d)); // representation of negative infinity
    d[0]=0;
    for(int i=0; i<2*n; i++){
        bool ch=0;
        for(int j=0; j<n; j++){
            for(array<ll,2> a: adj[j]){
                // d[a[1]]=max(d[a[1]], d[j]+a[0]);
                if(d[j]+a[0]>d[a[1]]){
                    if(a[1]==n-1){
                        ch=1;
                    }
                    d[a[1]]=d[j]+a[0];
                    
                }
            }
            if(i==n-1&&ch){
                cout << -1;
                return 0;
            }
        }
        // ans[i]=d[n-1];
    }
    cout << d[n-1];
    // if(n>1&&ans[n-2]<ans[n-1]){
    //     cout << -1;
    // }
    // else{
    //     cout << ans[n-1];
    // }
    
    
    return 0;
}