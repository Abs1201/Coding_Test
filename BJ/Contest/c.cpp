#include <bits/stdc++.h>
using namespace std;

int main() {
    int p3=0, p4=0;
    int a, b,c;
    cin >> a >> b >> c;
    p3=a/3, p4 = b/4;
    int aLeft = a%3;
    int bLeft = b%4;
    int aGap = (aLeft>0) ? (3-aLeft) : 0;
    int bGap = (bLeft>0) ? (4-bLeft) : 0;
    c-=aGap;
    if(aGap) p3++;
    c-=bGap;
    if(bGap) p4++;
    if(c<0){
        cout << -1;
        exit(0);
    }

    // TODO : 남은 c로 3,4 greedy
    bool check=0;
    for(int i=c/4; i>=0; i--){
        int remains = c- i*4;
        if(remains%3==0){
            p4+=i;
            p3+=remains/3;
            check=1;
            break;
        }
    }
    if(!check){
        cout << -1;
        exit(0);
    }
    cout << p3 << ' ' << p4;

    return 0;
}
