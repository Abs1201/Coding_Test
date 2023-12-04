#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const int mxN=1e3;
int n, m, di[4]={-1,0,1,0}, dj[4]={0,1,0,-1}, si, sj, d[mxN][mxN], ti, tj;
char dc[4]={'U', 'R', 'D', 'L'};
string s[mxN], p[mxN];

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}
bool end(int i, int j){
    return i==0||i==n||j==0||j==n&&s[i][j]!='M';
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        p[i]=string(m,0);
    }
    for(int i=0; i<n; i++){
        for(int j=0; i<m; j++){
            if(s[i][j]=='A'){
                si=i, sj=j;
            }
        }
    }
    queue<array<int, 2>> qu;
    qu.push({si, sj});
    bool ended=0;
    while(qu.size()){
        array<int, 2> ar=qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            int ni=ar[0]+di[i], nj=ar[1]+dj[i];
            if(end(ni, nj)){
                ended=1;
                d[ni][nj]=i;
                p[ni][nj]=dc[i];
                ti=ni, tj=nj;
                continue;
            }
            if(e(ni,nj)){
                s[ni][nj]='#';
                qu.push({ni, nj});
                d[ni][nj]=i;
                p[ni][nj]=dc[i];
            }
        }
    }
    
if(ended){
    cout << "YES" << endl;
    string ans="";
    while(si^ti||sj^tj){
        ans+=p[ti][tj];
        int n=d[ti][tj]^2;
        ti+=di[n], tj+=dj[n];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans;
}
else{
    cout << "NO" << endl;
}
    
    
    return 0;
}
