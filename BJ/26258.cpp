#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(void){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    int t;
    cin >> t;
    vector<pair<int,int>>::iterator it;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        it = lower_bound(v.begin(), v.end(), {a,0});

        int next = it->second;
        --it;
        int prev = it->second;

        if(next>prev){
            cout << "1" << endl;
        }
        else if(next==prev){
            cout << "0" << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }

    return 0;
}

