#include <bits/stdc++.h>

using namespace std;

int main(void){

    string s;
    cin >> s;
    if(s.length()==1){
        cout << 1;
        return 0;
    }
    //AAAACCCGGT

    int count = 0,ans=0;
    char former = 'A';
    for(char c : s){
        if(c == former){
            count++;
            ans = max(count, ans);
        }
        else{
            former = c;
            count = 1;
        }
    }
    cout << ans;
    return 0;
}