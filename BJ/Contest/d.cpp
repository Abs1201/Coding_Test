#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 특정 X로 K 쌍을 만들 수 있는지 확인
bool canMakePairs(vector<ll>& A, ll N, ll K, ll X) {
    ll pairs = 0;
    for (ll i = 0; i < N; i++) {
        ll take = min(X, A[i]); // X개 만큼만 뽑을 수 있음
        pairs += take / 2; // 뽑은 개수로 만들 수 있는 쌍
        if (pairs >= K) return true; // 이미 K 쌍이 충족되면 바로 true
    }
    return pairs >= K;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll totalPairs = 0;

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        totalPairs += A[i] / 2; // 가능한 전체 쌍 수
    }

    if (totalPairs < K) {
        cout << -1 << endl; // 애초에 만들 수 없는 경우
        return 0;
    }

    // 이진 탐색으로 최소 X 찾기
    ll left = 0, right = accumulate(A.begin(), A.end(), 0LL);
    ll result = -1;

    while (left <= right) {
        ll mid = (left + right) / 2; // 중간값
        if (canMakePairs(A, N, K, mid)) {
            result = mid; // 조건 만족, 최소값 갱신
            right = mid - 1; // 더 작은 값을 찾기 위해 왼쪽으로 이동
        } else {
            left = mid + 1; // 조건 만족하지 않으면 오른쪽으로 이동
        }
    }

    cout << result << endl;
    return 0;
}