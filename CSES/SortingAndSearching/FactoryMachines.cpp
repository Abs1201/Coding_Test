//Factory Machines
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int mxN=2e5;
 
bool check(ll* machines, ll n, ll mid, ll t){
    ll sum=0;
    for(int i=0; i<n; i++){
        sum+=mid/machines[i];
        if(sum>=t) return true;
    }
    return false;
}
 
int main(void){
    ll n, t;
    cin >> n>> t;
    //vector<ll> machines;
    ll machines[mxN];
 
    for(int i=0; i<n; i++){
        cin >> machines[i];
    }    
    ll low=1, high= (*max_element(machines, machines+n))*t;
    ll mid=(low+high)/2;
    ll ans;
    while(low <= high){
        if(check(machines, n, mid, t)){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    cout << ans;
 
    return 0;
}