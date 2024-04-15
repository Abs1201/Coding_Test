#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, k[mxN];

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }
    sort(k, k+n);
    vector<int> ans(1);

    for(int i=0; i<n; i++){
        if(*ans.rbegin() < k[i]) ans.push_back(k[i]);
    }

    cout << ans.size()-1;
    return 0;
}