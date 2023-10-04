#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxT=1e5;
ll t;


int main(void){
    cin >> t;

    for(ll i=0; i<t; i++){
        ll a, b;
        cin >> a >> b;
        // 10~16
        ll n=max(a,b);
        ll n2=(n-1)*(n-1);
        ll gap=abs(a-b);
        ll ans=n2+n;
        if(n&1){
            if(a<b){
                ans+=gap;
            }
            else{
                ans-=gap;
            }
        }
        else{
            if(a>b){
                ans+=gap;
            }
            else{
                ans-=gap;
            }
        }
        cout << ans << endl;
    }
    


    return 0;
}