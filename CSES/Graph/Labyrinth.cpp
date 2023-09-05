#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MxN = 1e3;
int n, m;
string s[MxN];

bool e(int i, int j){
    return i>=0&&i<m&&j>=0&&j<n&&s[i][j]=='.';
}
void dfs(int i , int j){
    s[i][j]='#';
    if(e(i-1, j)){
        dfs(i-1,j);
    }
    if(e(i, j-1)){
        dfs(i,j-1);
    }
    if(e(i+1, j)){
        dfs(i+1,j);
    }
    if(e(i,j+1)){
        dfs(i,j+1);
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(e(i,j)){
                dfs(i, j);
                ++ans;
            }
        }
    }


    return 0;
}