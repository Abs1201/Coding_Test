#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN = 2e5;
ar<int, 2> a[mxN];

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int c, t;
        cin >> c >> t;
        a[i]={c,t};
    }
    sort(a, a+n);
    int ans=0,tmp=0;
    for(int i=0,j=i; i<n; i++){
        while(a[i][1]>=a[j][0]&&j<n){
            tmp++;
            j++;
        }
        ans=max(ans,tmp);
        tmp=0;
        if(j>=n) break;
    }
    cout << ans;


    return 0;
}