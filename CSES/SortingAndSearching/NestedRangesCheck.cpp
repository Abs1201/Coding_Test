#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(array<ll, 5>& a1, array<ll, 5>& a2){
    return a1[2] < a2[2];
}

int main(void){
    ll n;
    cin >> n;
    vector<array<ll,5>> v;
    for(ll i=0, a, b; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b, i, 0, 0});
    }
    //sorted
    sort(v.begin(), v.end());
    ll b=v[0].at(1);
    for(int i=1; i<v.size(); i++){
        if(b>=v[i].at(1)){
            v[i].at(4)=1;
        }
        else{
            b=v[i].at(1);
        }
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<n; i++){
        cout << v[i].at(3) << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << v[i].at(4) << " ";
    }
    cout << endl;

    return 0;
}