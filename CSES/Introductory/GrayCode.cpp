#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<string> ans={"0", "1"};
 
 
int main(void){
    cin >> n;
    
    for(int i=0; i<n-1; i++){
        vector<string> tmp(ans);
        reverse(tmp.begin(), tmp.end());
        for(string& s:ans){
            s='0'+s;
        }
        for(string& s:tmp){
            s='1'+s;
        }
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    
    for(string s: ans){
        cout << s << endl;
    }
    
    return 0;
}