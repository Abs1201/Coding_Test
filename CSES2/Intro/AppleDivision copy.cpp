#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 20, mxP=1e9;

int n, p[20];

int main(void){
    cin >> n;
    ll s=0, ans=0;
    for(int i=0; i<n; i++){
        cin >> p[i], s+=p[i];
    }
    for(int i=0; i<1<<n; i++){
        ll cs=0;
        for(int j=0; j<n; j++){
            if(i>>j&1)
                cs+=p[i];
        }
        if(cs<=s/2)
            ans=max(ans,cs);
    }
    cout <<s-2*ans;


    return 0;
}

https://www.youtube.com/watch?v=Jrt4FntJIyM