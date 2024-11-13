#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int mxN=1e6;

int n, m;
string s[10], p[10];
int ri,rj,bi,bj,ti,tj;
int di[4]={-1,0,1,0}, dj[4]={0,-1,0,1}; // L U R D

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}

int main(void){
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='O'){
                ti=i, tj=j;
            }
            else if(s[i][j]=='R'){
                ri=i, rj=j;
            }
            else if(s[i][j]=='B'){
                bi=i, bj=j;
            }
        }
    }
    
    queue<pair<int,int>> qu;
    qu.push({si,sj});
    int cnt=1;
    while(!qu.empty()){
        pair<int,int> p=qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            int ni=p.first + di[i], nj=p.second+dj[i];
            while(e(ni, nj)){
                s[ni][nj]=cnt;
                ni+=di[i];
                nj+=dj[i];
            }

        }
    }
    

    return 0;
}

