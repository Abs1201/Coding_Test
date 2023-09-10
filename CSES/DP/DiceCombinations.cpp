#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e6, m=1e9+7;
vector<ll> dp(mxN, 0);

int Dice(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=0) return dp[n];
    int tmp=0;
    for(int i=1; i<=6; i++){
        tmp=(tmp+Dice(n-i))%m;
    }
    dp[n]=tmp;
    return tmp;
}

int main(void){
    int n;
    cin >> n;
    //f(n)=f(n-1)+f(n-2)+f(n-3)...+f(n-6);
    dp[0]=1;
    cout << Dice(n);


    return 0;
}