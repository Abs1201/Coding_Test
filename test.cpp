#include <bits/stdc++.h>
using namespace std;

int main(void){

    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(20);
    s.insert(20);
    s.insert(40);
    s.insert(70);
    s.insert(40);
    s.insert(50);

    set<int>::iterator iter;
    // int::iterator iter2;
    for(iter=s.begin(); iter!=s.end(); iter++){
        cout << *iter << endl;

    }
    if(iter==s.end()){
        cout << "all g" << endl;
    }
    cout << *(iter-8) << endl;
    return 0;
}