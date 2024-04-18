#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=2e5;

void solve(ll X, ll N, ll* P)
{
    // to store ranges
    set<pair<int, int> > ranges;
    ranges.insert({ 0, X });
    // to store range lengths
    multiset<ll> range_lengths;
    range_lengths.insert(X);

    for (int i = 0; i < N; i++) {
        // 3
        ll pos = P[i];
        // find the range in which pos lies
        auto it = ranges.upper_bound({ pos, 0 });
        it--;

        ll start = it->first;
        ll end = it->second;

        // Remove range [start, end] from ranges
        ranges.erase(it);
        // Remove length of range [start, end] from the
        // range_lengths
        range_lengths.erase(
            range_lengths.find(end - start));

        // Insert the new ranges
        ranges.insert({ start, pos });
        ranges.insert({ pos, end });
        range_lengths.insert(pos - start);
        range_lengths.insert(end - pos);

        // Print the last element of multiset as the answer
        cout << *range_lengths.rbegin() << "\n";
    }
}

// Drive Code
int main()
{
    ll X = 8, N = 3, P[] = { 3, 6, 2 };
    solve(X, N, P);
    return 0;
}