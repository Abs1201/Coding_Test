//제곱 ㄴㄴ수
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll a, b;
    cin >> a >> b;
    ll gap=b-a+1;
    ll ans=gap;
    vector<bool> v(gap, false);
    ll i=2;
    while(i*i<=b){
        ll seq=a/(i*i);
        if(a%(i*i) != 0) seq++;
        while(seq*i*i <=b){
            if(v[seq*i*i-a]==false){
                v[seq*i*i-a]=true;
                ans-=1;
            }
            seq+=1;
        }
        i+=1;
    }
    cout << ans;

    return 0;
}