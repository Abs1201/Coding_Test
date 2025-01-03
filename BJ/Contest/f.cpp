#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<array<int,3>> v;

int main(void){
    int n,k;
    cin >> n >> k;
    priority_queue<array<ll, 4>> pq; // value, a, b, num
    for(int i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        if(b>0){
            pq.push({b,a,b,1});
        }
    }
    ll ans=0;
    while(k--){
        array<ll,4> ar = pq.top();
        pq.pop();
        ans+=ar[0];
        ar[0] -= ar[1]*ar[3];
        ar[3]++;
        if(ar[0]>0){
            pq.push(ar);
        }
    }
    cout << ans;
    

    return 0;
}
