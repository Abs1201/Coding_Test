#include <bits/stdc++.h>
using namespace std;
//https://paido.tistory.com/16
const int mxN=3e4;
bool b[mxN+1];

bool IsPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2; i<n; i++){
        if(n%i>0) return 0;
    }
    return 1;
}

int solve(int a, int b){
    
}

int main(void){
    int a, b;
    cin >> a >> b;
    for(int i=1; i<=max(a,b); i++){
        b[i]=IsPrime(i);
    }
    cout << solve(a, b);


    return 0;
}