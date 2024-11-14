#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int mxN=1e6;

int n, m;
string s[10];
int ri,rj,bi,bj,ti,tj;
int di[4]={-1,0,1,0}, dj[4]={0,-1,0,1}; // U L D R

bool e(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}

struct ball{
    int rx, ry, bx, by, cnt;
};

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
                s[i][j]='.';
            }
            else if(s[i][j]=='B'){
                bi=i, bj=j;
                s[i][j]='.';
            }
        }
    }
    
    queue<ball> qu;
    qu.push({ri, rj, bi, bj, 0});
    bool vis[10][10][10][10];
    vis[ri][rj][bi][bj]=1;
    while(!qu.empty()){
        ball p=qu.front();
        qu.pop();
        if(p.cnt >= 10){
            cout << -1;
            return 0;
        }

        for(int i=0; i<4; i++){
            int nri=p.rx;
            int nrj=p.ry;
            int nbi=p.bx;
            int nbj=p.by;
            int rstep=0, bstep=0;

            while(e(nri+di[i], nrj+dj[i])){
                nri+=di[i];
                nrj+=dj[i];
                rstep++;
            }
            while(e(nbi+di[i], nbj+dj[i])){
                nbi+=di[i];
                nbj+=dj[i];
                bstep++;
            }
            // cout << nbi+di[i] << " " << nbj+dj[i] << endl;
            // cout << nri+di[i] << " " << nrj+dj[i] << endl;
            
            if(s[nbi+di[i]][nbj+dj[i]]=='O') continue;
            if(s[nri+di[i]][nrj+dj[i]]=='O'){
                // cout << "test" << endl;
                cout << p.cnt+1;
                return 0;
            }

            //겹칠때!
            if(nbi==nri && nbj==nrj){
                if(rstep>bstep){
                    nri-=di[i];
                    nrj-=dj[i];
                }
                else{
                    nbi-=di[i];
                    nbj-=dj[i];
                }
            }

            if(!vis[nri][nrj][nbi][nbj]){
                vis[nri][nrj][nbi][nbj]=1;
                qu.push({nri, nrj, nbi, nbj, p.cnt+1});
            }
        }
    }
    cout << -1;
    

    return 0;
}

