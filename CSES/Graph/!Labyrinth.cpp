#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, m;
int si, sj, ti, tj, ni[4]={0,0,-1,1};, nj[4]={-1,1,0,0};
char d[4]={'U', 'D', 'L', 'R'}; 
string s[mxN];
bool vis[i][j];
bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(s[i][j]='A'){
            si=i, sj=j;
        }
    }
    queue<array<int ,2>> qu;
    qu.push({si, sj});
    for(int i=0; i<4; i++){

    }
    
    
    vis[si][sj]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bfs(i, j);
        }
    }


    return 0;
}