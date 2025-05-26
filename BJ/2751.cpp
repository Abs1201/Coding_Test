#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e6;
int n, m;

int main(void){

    cin >> n;
    set<int> num;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        num.insert(x);
    }
    for(auto& e: num){
        cout << e <<'\n';
    }
    return 0;
}