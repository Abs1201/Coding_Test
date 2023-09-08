#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;

int main(void){
    int n, m;
    cin >> n >> m;
    set<array<int, 2>> s;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        s.insert({a,i});
    }    
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        auto it=s.lower_bound({a+1,0});
        if(it==s.begin()){
            cout << -1 << endl;
        }
        else{
            --it;
            cout << (*it)[0] << endl;
            s.erase(it);
        }
    }
    return 0;
}