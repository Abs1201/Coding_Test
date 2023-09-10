#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(void){
    ll n;
    cin >> n;
    ll sum=n*(n+1)/2;
    for(int i=0,a; i<n-1; i++){
        cin >> a;
        sum-=a;
    }
    cout << sum;
    
    return 0;
}