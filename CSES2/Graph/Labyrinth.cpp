#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, m, si, sj, ti, tj, di[4]={0,1,0,-1}, dj[4]={1,0,-1,0}, p[mxN][mxN];
char dc[mxN][mxN];
string s[mxN];

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='A')
                si=i, sj=j;
            else if(s[i][j]=='B')
                ti=i, tj=j;//, s[i][j]='.';
        }
    }
    queue<array<int, 2>> qu;
    qu.push({si, sj});
    while(qu.size()){
        array<int, 2> ar=qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            ni=ar[0]+di[i], nj=ar[1]+dj[i];
            if(e(ni, nj)){
                s[ni][nj]='#';
                
            }
        }
    }
    



    return 0;
}