#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=2e5;

int main(void){
    ll n,m;
    cin >> n >> m;
    ll flag=1;
    deque<int> q;
    for(int i=0; i<n; i++){
        q.push_back(i+1);
    }
    if(m==0){
        for(int i=0; i<q.size(); i++){
            cout << q[i] << " ";
        }
        return 0;
    }
    while(!q.empty()){
        int tmp=q.front();
        q.pop_front();
        if(flag){
            q.push_back(tmp);
            if(flag==m){
                flag=0;
            }
            else{//2
                flag++;
            }
        }
        else{
            cout << tmp << " ";
            flag++;
        }
        
    }



    return 0;
}