#include <bits/stdc++.h>

#define ll long long
const int mxN=1e3, mxM=1e3;
int n, m, si, sj, ti, tj, di[4]={-1,0,1,0}, dj[4]={0,1,0,-1},d[mxN][mxM];
char dc[4]={'L', 'D', 'R', 'U'};
string s[mxN], p[mxN];

bool e(int i, int j){
    return i<n && j<m && s[i][j]=='.';
}

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='A')
                si=i, sj=j;
            if(s[i][j]=='B')
                ti=i, tj=j;
        }
        p[i] = string(m,0);
    }
    queue<array<int,2>> qu;
    qu.push(si, sj);
    while(qu.size()){
       array<int,2> ar = qu.front();
       qu.pop();
       for(int i=0; i<4; i++){
           int ni=ar[0]+di[i], nj=ar[1]+dj[i];
           if(!e(ni, nj)){
               continue;
           }
           qu.push(ni, nj);
           d[ni][nj]=i;
           p[ni][nj]=dc[i];
       }
    }
    if(p[ti][tj]){
        string ans="";
        while(ti^si||tj^sj){
            ans+=p[ti][tj];
            int t=d[ti][tj]^2;
            ti+=di[t], tj+=dj[t];
        }
        ans.reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
