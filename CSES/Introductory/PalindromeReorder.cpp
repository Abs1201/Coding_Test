#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2e5;

int main(void){
    string s;
    cin >> s;
    char c[26]={}, c1=0;
    for(char d: s){
        ++c[d-'A'];
    }
    for(int i=0; i<26; i++){
        c1+=c[i]&1;
    }
    if(c1>1){
        cout <<"NO SOLUTION";
        return 0;
    }
    cout << "test" << endl;
    return 0;
} 
//AAABAA