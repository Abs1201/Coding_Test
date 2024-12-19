#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mxN=1e6;

bool hansu(int n){
    int n1=n%10/1;
    int n2=n%100/10;
    int n3=n%1000/100;

    return n3-n2 == n2-n1;
}

int main(void){
    int n;
    cin >> n;
    int ans=99;
    for(int i=111; i<=n; i++){
        if(hansu(i)) ans++;
    }
    if(n<=99) ans=n;
    if(n==1000) ans--;
    cout << ans;


    return 0;
}