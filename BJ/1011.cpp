#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t, x, y;

int main(void){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> x >> y;
        ll gap=y-x;
        ll n=1;
        while((n+1)*(n+1) <= gap){
            n++;
        }
        cout << 2*n-1 << endl;
    }

    return 0;
}