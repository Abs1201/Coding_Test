#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mxN=50;

int n, arr[mxN];

bool compare(pair<int, int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int main(void){
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        v[i].first=i;
    }
    sort(v.begin(), v.end(), compare);
    for(pair<int,int>& e: v){
        cout << e.first << ' ';
    }

    return 0;
}