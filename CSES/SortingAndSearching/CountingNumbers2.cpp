#include <bits/stdc++.h>
using namespace std;

int solve(vector<array<int,2>>& v, int a, int b){
    v[a][1]=b;
    v[b][1]=a;
    sort(v.begin(), v.end());
    int ans=0;
    int tmp=-1;
    for(int i=0; i<v.size(); i++){
        if(tmp>v[i][1] || i==v.size()-1) ans++;
        if(tmp>v[i][1] && i==v.size()-1) ans++;
        tmp=v[i][1];
    }
    return ans;
}

int main(void){
    int n, m;
    cin >> n >> m;
    vector<array<int,2>> v;
    for(int i=0, a; i<n; i++){
        cin >> a;
        v.push_back({a, i});
    }
    vector<int> ans;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        ans.push_back(solve(v,a,b));
    }
    for(int a: ans){
        cout << a << " ";
    }


    return 0;
}