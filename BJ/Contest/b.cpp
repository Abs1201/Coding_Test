#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    int s=0;
    for(int i=0; i<4; i++){
        cin >> a[i];
    }
    s=(a[0]+a[1]-1)%4;
    s=(s+a[2]+a[3]-1)%4;
    cout << s+1;


    return 0;
}
