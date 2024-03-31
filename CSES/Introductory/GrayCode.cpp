#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e7;

int n;
string ans[mxN];
int main(void){
    cin >> n;
    bool b=1;
    int s,s2;
    for(int i=0; i<n; i++){
        s=pow(2,i);
        s2=s;
        for(int j=0; j<pow(2,n); j++){
            --s2;
            if(b){
                if(s2<=0){
                    s2=s, b=!b;
                }
                ans[j]='0'+ans[j];
            }
            else{
                if(s2<=0){
                    s2=s, b=!b;
                }
                ans[j]='1'+ans[j];
            }
        }
    }

    for(int i=0; i<pow(2,n); i++){
        cout << ans[i] << endl;
    }
    
    
    return 0;
}