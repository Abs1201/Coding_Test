#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;

int main(void){
    int n;
    cin >> n;
    map<int, int> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        // m.insert({a, i});
        m[a]=i;
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        while(i<n && m[i] < m[i+1]){
            i++;
        }
        ans++;
    }

    

    return 0;
}