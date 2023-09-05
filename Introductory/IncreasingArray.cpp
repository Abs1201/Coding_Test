#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

    int n;
    cin >> n;
    ll former=0,ans=0, x;
    for(int i=0; i<n; i++){
        cin >> x;
        if(former>x){
            ans+=(former-x);
        }
        else{
            former = x;
        }
    }
    cout << ans;


    return 0;
}