#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



int main(void){
    int n, a, b;
    cin >> n >> a >> b;
    int cnt=1;
    while(1){
        int range = pow(2, cnt);
        for(int i=0; i<=n; i+=range){
            if(a>i && a<=(i+range) && b>i && b<=(i+range)){
                cout << cnt;
                exit(0);
            }
        }
        cnt++;
    }

    cout << -1;

    return 0;
}