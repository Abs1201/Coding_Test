#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const int mxN=1e3;
int n, m, d[mxN][mxN], si, sj, di[4]={-1,0,1,0}, dj[4]={0,1,0,-1}, ti=-1,tj=-1;
char dc[4]={'U', 'R', 'D', 'L'};
string s[mxN], p[mxN];

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}
bool end(int i, int j){
    return i==0||i==n-1||j==0||j==m-1&&s[i][j]=='.';
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; i++){
            if(s[i][j]=='A'){
                si=i, sj=j;
            }
        }
        p[i]=string(m, 0);
    }
    
    queue<array<int,2>> qu;
    
    bool found=0;
    qu.push({si, sj});
    while(qu.size() && !found){
        array<int,2> ar=qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            int ni=ar[0]+di[i], nj=ar[1]+dj[i];
            if(e(ni, nj)){
                s[ni][nj]='#';
                d[ni][ni]=i;
                p[ni][nj]=dc[i];
                if(end(ni, nj)){
                    ti=ni, tj=nj;
                    found=1;
                    continue;
                }
            }
        }
    }
    if(~ti&&~tj){
        cout << "NO" << endl;
    }
    else{
        string ans="";
        while(si^ti||sj^tj){
            ans+=p[ti][tj];
            int ni=d[ti][tj]^2;
            ti+=di[ni], tj+=dj[ni];
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    
    return 0;
}
