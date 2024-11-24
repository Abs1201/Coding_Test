#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mxN=10;

int dp[mxN][mxN]
char di[8]={-1,0,1,0,-1,-1,1,1}, dj[8]={0,-1,0,1,1,-1,1,-1}; //u,l,d,r  1,11,5,8


int countMaxStudent(int x, int y, string* s){
    for(int i=0; i<8;i++){
        int ni=x+di[i], nj=y+dj[i];
        for(e(ni, nj)){
            
        }
    }
}

int getMaxStudent(int n, int m, string* s){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = countMaxStudent(i,j,s);
        }
    }
    return dp[n-1][m-1];
}


int main(void){
    int t, n ,m;
    string s[mxN];  

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        for(int j=0; j<n; j++){
            cin >> s[i];
        }
        cout << getMaxStudent(n, m, s) << endl;
    }

    return 0;
}