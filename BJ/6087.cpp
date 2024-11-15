#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s[100];
int p[100][100], ans[100][100];
int w,h;
int si,sj, ti,tj;
bool b;
int di[4]={-1,0,1,0}, dj[4]={0,-1,0,1}; // u l d r

bool e(int i, int j){
    return i>=0&&i<h&&j>=0&&j<w&&s[i][j]=='.';
}
int main(void){
    cin >> w >> h;
    b=0;
    for(int i=0; i<h; i++){
        cin >>s[i];
        for(int j=0; j<w; j++){
            if(s[i][j]=='C' && !b){
                si=i, sj=j;
                b=!b;
            }
            else if(s[i][j]=='C' && b){
                ti=i, tj=j;
                s[i][j]='.';
            }
        }
    }

    memset(p, -1, sizeof(p));
    memset(ans, 0x3f, sizeof(ans));

    bool vis[100][100] = {0};
    queue<pair<int,int>> qu;
    qu.push({si, sj});
    ans[si][sj]=0;
    while(!qu.empty()){
        pair<int,int> pa = qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            int ni=pa.first, nj=pa.second;
            int nii=ni+di[i], njj=nj+dj[i];
            if(e(nii, njj)){
                int tmp=ans[ni][nj]+(p[ni][nj]!=i);
                if(p[nii][njj]>tmp){
                    p[nii][njj]=tmp;
                    qu.push({nii, njj});
                }
            }
        }
    }
    cout << ans[ti][tj]-1;


    // ans-=1;

    return 0;
}