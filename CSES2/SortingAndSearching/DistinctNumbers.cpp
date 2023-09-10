#include <bits/stdc++.h>
using namespace std;

#define ll long long
// number of distinct values == 다른값을 갖는 수.
int main(void){
    int n;
    cin >> n;
    set<int> s;
    for(int i=0, a; i<n; i++){
        cin >> a;
        s.insert(a);
    }
    cout << s.size();

    return 0;
}