// Sum of Three Values
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    // 1 2 5 7
    vector<pair<ll, ll>>::iterator it1, it2, it3;
    it1 = v.begin(), it2 = it1 + 1, it3 = v.end() - 1;
    bool hasAnswer = 0;
    while (it2 < it3)
    {
        while (it2 < it3)
        {
            ll sum = it1->first + it2->first + it3->first;
            if (sum == x)
            {
                hasAnswer = 1;
                break;
            }
            else
            {
                if (sum > x)
                {
                    it3--;
                }
                else
                {
                    it2++;
                }
            }
        }
        if(hasAnswer) break;
        it1++;
        it2=it1+1;
        it3=v.end()-1;
    }

    if (hasAnswer)
    {
        cout << it1->second+1 << " " << it2->second+1 << " " << it3->second+1 << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}