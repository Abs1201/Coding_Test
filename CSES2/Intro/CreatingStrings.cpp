#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 8;

int main(void){
    string s;
    cin >> s;

    int ans=1;
    sort(s.begin(), s.end());
    while(next_permutation(s.begin(), s.end())){
        ans++;
    }
    cout << ans << endl;
    sort(s.begin(), s.end());
    cout << s << endl;
    while(next_permutation(s.begin(), s.end())){
        cout << s << '\n';
    }

    
    return 0;
}