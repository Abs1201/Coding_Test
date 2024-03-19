#include <bits/stdc++.h>
using namespace std;

void tmp(){
    int a;
    return;
}

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
    for(iter=s.begin(); iter!=s.end(); ++iter){
        cout << *iter << endl;
    }
    if(iter==s.end()){
        cout << "all g" << endl;
    }

    // prefix, postfix
    int a=10;
    int b=++a;
    cout << a << " " << b << endl;

    a=10;
    b=a++;
    cout << a << " " << b << endl;

    // Q1
    a=1, b=2;
    a=a|b++;
    cout << a << endl;

    
    
    return 0;
}