#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e3, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
const char dc[4]={'U', 'R', 'D', 'L'};
int n, m, si, sj, ti, tj;
string s[mxN], p[mxN]; 

bool e(int i, int j){
    return i<n&&i>=0&&j<m&&j>=0&&s[i][j]!='.';
}

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='A')
                si=i, sj=j;//, s[i][j]='.';
            if(s[i][j]=='B')
                ti=i, tj=j, s[i][j]='.';
        }
        p[i]=string(n,0);
    }
    queue<ar<int,2>> qu;
    qu.push({si, sj});
    while(qu.size()){
        ar<int, 2> u = qu.front();
        u.pop();
        for(int k=0; k<4; k++){
            int ni= u[0]+di[k], nj=u[1]+dj[k];
            if(!e(ni, nj))
                continue;
            qu.push({ni, nj});
            s[ni][nj]='#';
            p[ni][nj]=dc[k];
        }
    }
    if(p[ti][tj]){
        cout << "YES" << endl;
        string t;
        reverse(t.begin(), t.end());
        cout << t.size() << endl;
        cout << t;
    }

    return 0;
}