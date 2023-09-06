#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;
array<int,2> ar[mxN];

int main(void){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        // cin >> ar[i][0] >> a[i][1];
        cin >> ar[i][1] >> ar[i][0];
    }
    sort(ar, ar+n);
    int ans=0, tmp=0;
    for(int i=0; i<n; i++){
        if(ar[i][1]>=tmp){
            ans++;
            tmp=ar[i][0];
        }
        
    }
    cout << ans;
    


    return 0;
}