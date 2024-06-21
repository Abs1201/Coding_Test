#include <bits/stdc++.h>
using namespace std;

int main(void){

    map<int, int> m;
    m[0]=1;
    m[0]++;
    m.insert({1,3});
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m.size() << endl;
    
    // set<array<int,2>> s;
    // s.insert({0,1});

    // cout << s[0] << endl;

    // cout << s.size() << endl;

    return 0;
}