//미친.. multicset과 upper_bound :)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mxN=2e5;
int main(void){
    int n, k[mxN];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }
    multiset<ll> ans;
    multiset<ll>::iterator it;
    for(int i=0; i<n; i++){
        it=ans.upper_bound(k[i]);
        if(it==ans.end()) ans.insert(k[i]);
        else{
            ans.erase(it);
            ans.insert(k[i]);
        }
    }

    cout << ans.size();


    return 0;
}