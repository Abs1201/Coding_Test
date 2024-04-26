#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<vector<ll> >& timings, ll N)
{
    vector<vector<ll> > vec(N, vector<ll>(3));
    for (int i = 0; i < N; i++) {
        vec[i][0] = timings[i][0];
        vec[i][1] = timings[i][1];
        vec[i][2] = i;
    }

    sort(vec.begin(), vec.end());

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> occupiedRooms;

    int roomCnt = 0;

    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        ll arrivalTime = vec[i][0];
        ll departureTime = vec[i][1];
        ll idx = vec[i][2];

        if (occupiedRooms.empty()
            || occupiedRooms.top().first >= arrivalTime) {
            roomCnt += 1;
            occupiedRooms.push({ departureTime, roomCnt });
            ans[idx] = roomCnt;
        }
        else {
            int vacantRoom = occupiedRooms.top().second;
            occupiedRooms.pop();
            occupiedRooms.push(
                { departureTime, vacantRoom });
            ans[idx] = vacantRoom;
        }
    }

    cout << roomCnt << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main(){
    ll N = 3;
    vector<vector<ll> > timings
        = { { 1, 2 }, { 2, 4 }, { 4, 4 } };

    solve(timings, N);
    return 0;
}
