#include <bits/stdc++.h>
using namespace std;

int main(void){

    stack<int> s;
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    int tmp=s.top();
    cout << tmp << endl;
    
    
    return 0;
}