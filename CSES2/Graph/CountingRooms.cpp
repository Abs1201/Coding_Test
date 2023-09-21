#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, m;
string s[mxN];

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}
void dfs(int i, int j){
    if(!e(i,j)){
        return;
    }
    s[i][j]='#';
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i, j-1);
    dfs(i, j+1);
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }    
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(e(i,j)){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;


    return 0;
}