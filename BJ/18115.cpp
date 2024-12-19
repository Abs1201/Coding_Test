#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mxN=1e6;

void skill2(deque<int>& dq, int n){
    int tmp = dq.front();
    dq.pop_front();
    dq.push_front(n);
    dq.push_front(tmp);
}

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    reverse(v.begin(), v.end());
    deque<int> ans;
    for(int i=1, j=0; i<=n; i++, j++){
        if(v[j]==1){
            ans.push_front(i);
        }
        if(v[j]==2){
            skill2(ans, i);
        }
        if(v[j]==3){
            ans.push_back(i);
        }
    }
    for(auto& e: ans){
        cout << e << ' ';
    }


    return 0;
}