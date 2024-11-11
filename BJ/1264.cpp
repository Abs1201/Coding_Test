#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    char c[10] = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
    map<char, int> m;   
    while(1){
        getline(cin, s);
        if(s=="#") break;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        int cnt=0;
        for(int i=0; i<10; i++){
            cnt+=m[c[i]];
        }
        cout << cnt << endl;
        m.clear();
    }

    return 0;
}