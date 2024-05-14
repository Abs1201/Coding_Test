#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back({a,i});
    }
    sort(v.begin(), v.end());

    vector<pair<ll,ll>>::iterator it1,it2,it3, it4;
    it1=v.begin();
    it2=it1+1;
    it3=it2+1;
    it4=v.end()-1;
    bool hasAnswer=0;

    while(it3<it4){
        while(it3<it4){
            while(it3<it4){
                ll sum=it1->first+it2->first+it3->first+it4->first;
                if(sum==x){
                    hasAnswer=true;
                    break;
                }
                else{
                    if(sum<x){
                        it3++;
                    }
                    else{
                        it4--;
                    }
                }
            }
            if(hasAnswer) break;
            it2++;
            it3=it2+1;
            it4=v.end()-1;
        }
        if(hasAnswer) break;
        it1++;
        it2=it1+1;
        it3=it2+1;
        it4=v.end()-1;
    }

    if(hasAnswer){
        cout << it1->second+1 << " " << it2->second+1 << " " << it3->second+1 << " " << it4->second+1 << endl;
    }
    else{
        cout << "IMPOSSIBLE";
    }




    return 0;
}