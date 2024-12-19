#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
#define ll long long

ll diceFace[6];

int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> diceFace[i];
    }

    if (n == 1) {
        // Special case: single dice
        ll total = accumulate(diceFace, diceFace + 6, 0LL);
        ll maxFace = *max_element(diceFace, diceFace + 6);
        cout << total - maxFace << endl;
        return 0;
    }

    // Find the minimum values for 1, 2, and 3 faces
    ll min1 = *min_element(diceFace, diceFace + 6);

    ll min2 = LLONG_MAX;
    vector<pair<int, int>> adj2 = {{0, 1}, {0, 2}, {0, 3}, {0, 4},
                                   {1, 5}, {2, 5}, {3, 5}, {4, 5}};
    for (auto [x, y] : adj2) {
        min2 = min(min2, diceFace[x] + diceFace[y]);
    }

    ll min3 = LLONG_MAX;
    vector<tuple<int, int, int>> adj3 = {{0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4},
                                         {5, 1, 2}, {5, 1, 3}, {5, 2, 4}, {5, 3, 4}};
    for (auto [x, y, z] : adj3) {
        min3 = min(min3, diceFace[x] + diceFace[y] + diceFace[z]);
    }

    // Count visible faces
    ll oneFace = (n - 2) * (n - 2) * 5 + (n - 2) * 4;
    ll twoFace = (n - 2) * 8 + 4;
    ll threeFace = 4;

    // Calculate the total visible sum
    ll ans = oneFace * min1 + twoFace * min2 + threeFace * min3;

    cout << ans << endl;
    return 0;
}
