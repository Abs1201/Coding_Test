#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll N, ll* songs)
{
    ll start = 0, ans = 0;
    // Map to store the last occurrence of all the
    // characters
    map<ll, ll> mp;

    // Increment end pointer character by character
    for (ll end = 0; end < N; end++) {
        // If the current song is not present in the map
        if (mp.find(songs[end]) == mp.end())
            mp.insert({ songs[end], end });
        else {
            // If the current song is present in the map and
            // is inside the window
            if (mp[songs[end]] >= start)
                start = mp[songs[end]] + 1;
            // Update the last occurrence of current
            // character to the current index
            mp[songs[end]] = end;
        }
        // Update ans to store the maximum length of range
        // of unique values
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main()
{
    // Sample Input
    ll N = 8;
    ll songs[N] = { 1, 2, 1, 3, 2, 7, 4, 2 };

    cout << solve(N, songs) << "\n";
}