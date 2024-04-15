#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s[8];

void solve(string s, int row, int& ans){
    int count=0;
    for(int i=0; i<8; i++){
        if(s[row][i]=='.'){
            s[row]="********";
            for(int j=row; j<8; j++){
                s[j][i]='*';
                //TODO: condition
                s[j+1][i+1]='*';
                s[j-1][i-1]='*';
            }
        }
        if(row==7 && s[row][i]!='*'){
            count++;
        }
    }
    ans+=count;
}

int main(void){
    for(int i=0; i<8; i++){
        cin >> s[i];
    }
    int ans=0;
    solve(s, 0, ans);
    cout << ans;


    return 0;
}