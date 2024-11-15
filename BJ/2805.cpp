#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 1e6;
int n, m;

int main(void) {
    cin >> n >> m;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    ll start = 0, end = w.back();
    int ans = 0;

    while (start <= end) {
        ll gap = 0;
        ll mid = (start + end) / 2;
        
        for (int i = 0; i < n; i++) {
            if (mid < w[i]) {
                gap += (w[i] - mid);
            }
        }
        
        if(gap>=m)ans = mid;
        
        if (gap > m) {
            start = mid+1;
        } else if(gap<m){
            end = mid-1;
        }
        else break;
    }

    cout << ans << endl;

    return 0;
}
