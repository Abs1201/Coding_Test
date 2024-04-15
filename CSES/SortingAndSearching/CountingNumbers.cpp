#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<array<int, 2>> v;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    int ans=0;
    int tmp=-1;

    for(int i=0; i<n; i++){
        if(tmp>v[i][1] || i==n-1){
            ans++;
        }
        if(i==n-1&&tmp>v[i][1]){
            ans++;
        }
        tmp = v[i][1];
    }
    cout << ans;

    return 0;
}