#include <bits/stdc++.h>

using namespace std;

const int index =1e9;
int x[index];

int main(void){
    int n;
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();



    return 0;
}