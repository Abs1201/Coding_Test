#include <bits/stdc++.h>
using namespace std;

int main(void){

    set<pair<int, int>> s;
    s.insert({0,8});
    s.insert({0,4});
    set<pair<int, int>>::iterator it;
    // it=s.upper_bound({3,0});
    it=s.upper_bound({0,3});
    cout << it->first << " " << it->second << endl;

    
    
    return 0;
}