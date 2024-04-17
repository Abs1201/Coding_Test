//240417-1
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2e5;

int n;//,  k[mxN];

bool compare(array<ll, 2>& a1, array<ll,2>& a2){
    return a1[0] > a2[0];
}

int main(void){
    cin >> n;
    vector<array<ll,2>> k;
    for(int i=0, a; i<n; i++){
        cin >> a;
        k.push_back({a, i});
    }
    sort(k.begin(), k.end(), compare);
    //1 2 3 5 8
    // 82 52.1 31 23 14 0.12.5
    //내림차순
    //순서번호가 오르면 현재가중치 갱신, ans 변화없음.
    //          내려가면 벡터에서 가중치 낮은거부터 돌아서 찾고 없으면 추가.
    vector<array<ll,2>> ans;
    ans.push_back(k[0]);
    ll w=ans[0][0];
    for(int i=1; i<n; i++){
        if(k[i][1]>k[i-1][1]){
            w=k[i][0];
        }    
        else{
            //ans.find()
        }
    }

    cout << ans.size();

    return 0;
}