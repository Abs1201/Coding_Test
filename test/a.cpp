//josephus problem 1
#include <bits/stdc++.h>
using namespace std;

int n;

int main(void){
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(i);
    }
    set<int>::iterator iter;
    // while(s.begin()!=s.end()){

    // }
    cout << sizeof(iter) << endl;

    return 0;
}