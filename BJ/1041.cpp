#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll diceFace[6];

ll expo1(ll n){
    return 5*n*n-16*n+12;
}
ll expo2(ll n){
    return 8*n-12;
}
ll expo3(ll n){
    return 4;
}

int main(void){
    ll n;
    cin >> n;
    for(int i=0; i<6; i++){
        cin >> diceFace[i];
    }

    ll ans=0;
    if(n==1){
        ll max1 = *max_element(diceFace, diceFace+6);
        for(auto& e: diceFace){
            ans+=e;
        }
        ans-= max1;
    }
    else{
        ll min1 = *min_element(diceFace, diceFace+6);
        ll min2=0, min3=0;
        vector<ll> min2Arr;
        min2Arr.push_back(diceFace[0]+diceFace[1]);
        min2Arr.push_back(diceFace[0]+diceFace[2]);
        min2Arr.push_back(diceFace[0]+diceFace[3]);
        min2Arr.push_back(diceFace[0]+diceFace[4]);
        min2Arr.push_back(diceFace[1]+diceFace[2]);
        min2Arr.push_back(diceFace[1]+diceFace[3]);
        min2Arr.push_back(diceFace[4]+diceFace[2]);
        min2Arr.push_back(diceFace[4]+diceFace[3]);
        min2Arr.push_back(diceFace[5]+diceFace[1]);
        min2Arr.push_back(diceFace[5]+diceFace[2]);
        min2Arr.push_back(diceFace[5]+diceFace[3]);
        min2Arr.push_back(diceFace[5]+diceFace[4]);
        min2 = *min_element(min2Arr.begin(), min2Arr.end());

        min3 = diceFace[0]+diceFace[1]+diceFace[2];
        min3 = min(min3, diceFace[0]+diceFace[1]+diceFace[3]);
        min3 = min(min3, diceFace[0]+diceFace[2]+diceFace[4]);
        min3 = min(min3, diceFace[0]+diceFace[3]+diceFace[4]);
        min3 = min(min3, diceFace[5]+diceFace[1]+diceFace[2]);
        min3 = min(min3, diceFace[5]+diceFace[1]+diceFace[3]);
        min3 = min(min3, diceFace[5]+diceFace[2]+diceFace[4]);
        min3 = min(min3, diceFace[5]+diceFace[3]+diceFace[4]);

        ans = expo1(n)*min1 + expo2(n)*min2 + expo3(n)*min3;
    }


    cout << ans;


    return 0;
}