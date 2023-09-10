#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n;
vector<int> adj[mxN], ans;

int main(void){ 
    cin >> n;
    for(int i=0, a; i<n-1; i++){
        cin >> a;
        adj[a-1].push_back(i);
    }
    int a=0;
    for(int i=n-1; i>=0; i--){
        a+=adj[i].size();
        ans.push_back(a);
    }
    for(int i=n-1; i>=0; i++){
        cout << ans[i] << " ";
    }

    return 0;
}