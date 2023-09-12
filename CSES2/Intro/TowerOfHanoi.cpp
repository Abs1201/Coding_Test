#include <bits/stdc++.h>
using namespace std;

void Solve(int n, int s, int e, int t){
    if(n==0){return;}
    Solve(n-1, s, t, e);
    cout << s << " " << e << endl;
    Solve(n-1, t, e, s);
}
int Count(int n){
    if(n<=1){
        return 1;
    }
    return Count(n-1)*2+1;
}

int main(void){
    int n;
    cin >> n;
    // cout << Count(n) << endl;
    cout << (int)pow(2,n)-1 << endl;
    Solve(n, 1, 3, 2);

    return 0;
}