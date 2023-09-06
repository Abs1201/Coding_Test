#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;
int a[mxN];
int main(void){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int ans=0;
    for(int i=n-1, j=0; j<i;){
        if(j<i&&a[i]+a[j]<=x){
            ans++;
            i--;
            j++;
        }
        else{
            i--;
        }
        
    }
    cout << n-ans;


    return 0;
}