//Reading Books
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int mxN=2e5;
 
int main(void){
 
    int n;
    cin >> n;
    ll times[mxN];
    for(int i=0; i<n; i++){
        cin>>times[i];
    }
    sort(times, times+n);
    ll sum=0;
    for(int i=0; i<n-1; i++){
        sum+=times[i];
    }
    if(sum<times[n-1]){
        cout << 2*times[n-1];
    }
    else{
        cout << sum+times[n-1];
    }
 
 
    return 0;
}