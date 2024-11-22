#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int CountBW(int x, int y, string* s){
    int b=0,w=0;
    bool flag=1;
    int x2=x+8, y2=y+8;
    for(int i=x; i<x+8; i++){
        for(int j=y; j<y+8; j++){
            if(s[i][j]=='B'){
                if(flag) w++;
                else b++;
            }
            else{
                if(flag) b++;
                else w++;
            }
            flag=!flag;
        }
        flag=!flag;
    }
    return min(b,w);

}

int main(void){
    int n,m;
    string s[50];
    cin >> n >> m;
    for(int i=0;i<n; i++){
        cin >> s[i];
    }
    int ans=INT_MAX;
    for(int i=0; i<n-7; i++){
        for(int j=0; j<m-7; j++){
            ans=min(ans,CountBW(i,j,s));
        }
    }
    cout << ans;


    return 0;
}