#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(void){
    set<int> s;
    s.insert(2);
    s.insert(5);
    s.insert(6);
    s.insert(9);

    auto it=s.upper_bound(2);
    // if(it==s.begin()){
    //     cout << *it << endl;
    // }
    cout << *it << endl;


    
    return 0;
}