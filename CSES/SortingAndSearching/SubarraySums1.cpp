#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll n, x;
    cin >> n >> x;
    vector<ll> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    vector<ll>::iterator it=v.begin(), it2=v.begin();
    ll sum=0;
    int count=0;
    //cout << "f: " << *it << " " << *it2 << endl;
    while(it!=v.end()){
        while(it2!=v.end() && sum<x){
            
            sum+=*it2;
            //cout << "sum: " << sum << endl;
            it2++;
        }
        while(sum>x){
            //cout << "sum: " << sum << endl;
            sum-=*it;
            it++;
        }
        if(sum==x){
            count++;
        }
        if(it<it2){
            sum-=*it;
            it++;
        }
        

    }
    cout << count << endl;
    

//5 1
// 10 9 1 1 2

    return 0;
}