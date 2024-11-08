#include <bits/stdc++.h>
using namespace std;


int main(void){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int a,b;
        cin >> a >> b;
        a%=10;
        int tmp=a;
        for(int i=0; i<b-1; i++){
            a*=tmp;
            a%=10;
        }
        if(a==0) cout << 10 << endl;
        else cout << a << endl;
    }


    return 0;
}