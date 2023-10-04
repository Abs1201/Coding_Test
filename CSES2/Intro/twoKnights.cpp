#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxT=1e4;
ll n;


int main(void){
    cin >> n;
    ll ans;
    for(int i=1; i<=n; i++){
        ll s=i*i, s2=0;
        ans=s*(s-1)/2;
        if(i>2){
            s2=(i-1)*(i-2)*4;
        }
        ans-=s2;
        cout << ans << endl;
    }
    
    
    


    return 0;
}