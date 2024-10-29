//Labyrinth
#include <bits/stdc++.h>
using namespace std;

int n, m, di[4]={-1, 0, 1, 0}, dj[4]={0,-1,0,1}, si, sj, ei, ej;
string s[1000], p[1000];
char dc[4]={'L', 'U', 'R', 'D'};


int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='A'){
                si=i, sj=j;
            }
        }
    }


    return 0;
}