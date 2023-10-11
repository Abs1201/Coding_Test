#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 20, mxP=1e9;

int a[mxN];

int main(void){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    /* 1 2 3 4 7
        a: 7 2 
        b: 4 3 1
    */
    sort(a+0, a+n);
    int s1=0, s2=0;
    for(int i=n-1; i>=0; i--){
        if(s1<s2){
            s1+=a[i];
        }
        else{
            s2+=a[i];
        }
    }
    cout << abs(s1-s2);


    return 0;
}