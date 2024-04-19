#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=2e5;

int main(void){
    int n;
    cin >> n;
    bool flag=false;
    queue<int> q;
    for(int i=0; i<n; i++){
        q.push(i+1);
    }
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        if(flag){
            cout << tmp << " ";
        }
        else{
            q.push(tmp);
        }
        flag=!flag;
    }



    return 0;
}