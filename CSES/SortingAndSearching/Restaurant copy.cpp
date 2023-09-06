#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN = 2e5;


int main(void){
    int n;
    cin >> n;
    set<array<int,2>> s;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        s.insert({a, 1});
        s.insert({b, -1});
    }
    int ans=0, tmp=0;
    for(auto a: s){
        tmp+=a[1];
        ans=max(ans,tmp);
    }
    cout << ans;


    return 0;
}