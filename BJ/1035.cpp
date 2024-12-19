#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char board[5][5];
int cnt;
bool vis[5][5];
int di[4]={-1,0,1,0}, dj[4]={0,-1,0,1};

bool e(int r, int c){
    return r<5 && r>=0 && c<5 && c>=0 && board[r][c]=='*' && vis[r][c]=0;
}
void dfs(int r, int c){
    vis[r][c]=1;
    cnt++;
    for(int i=0; i<4; i++){
        int ni=r+di[i], nj=c+dj[i];
        if(e(ni, nj)){
            dfs(ni, nj);
        }
    }
}

int main() {
    for(int i=0; i<5; i++){
        cin >> board[i];
    }
    
    bool vis[5][5];
    memset(vis, 0, sizeof(vis));

    int maxCnt=0, maxI, maxJ;
    int num=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int cnt=0;
            if(e(i, j)){
                dfs(i,j);
                num++;
                if(cnt > maxCnt){
                    maxCnt=cnt;
                    maxI=i;
                    maxJ=j;
                }
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){

        }
    }

    num--;
    while(num>0){
        --num;
        
    }    

    return 0;
}
