//apple division
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=1000;
 
int n, q[mxN];
 
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> q[i];
    }
    int ans[mxN];
 
    for(int i=0; i<n; i++){
        int sum=0;
        int j=0, k, k2;
        for(j=0, k=q[i]-sum; k>0; j++){
            if(k>0) k2=k;
            sum+=9*pow(10,j);
        }
        int q=
 
 
    }
 
 
    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }
 
    return 0;
}
