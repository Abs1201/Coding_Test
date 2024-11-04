#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, m;
vector<int> v;

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    vector<int>::iterator it = v.begin(), it2=v.begin();
    ll sum=0;
    int ans=0;
    if(m==0) ans++;
    while(it2!=v.end()){
        sum+=*it2;
        if(sum==m) ans++;
        while(it<it2 && sum>=m){
            sum-=*it;
            it++;
            if(sum==m) ans++;
        }
        it2++;
    }
    
    cout << ans << endl;

    return 0;
}