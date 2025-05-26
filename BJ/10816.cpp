#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int lower_bound(vector<int>& v, int target) {
    int left = 0, right = v.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(vector<int>& v, int target) {
    int left = 0, right = v.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (v[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v,w;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        w.push_back(a);
    }

    for(int i=0; i<m; i++){
        int lower = lower_bound(v, w[i]);
        int upper = upper_bound(v, w[i]);
        int ans = upper - lower;
        cout << ans << " ";
    }

    return 0;
}