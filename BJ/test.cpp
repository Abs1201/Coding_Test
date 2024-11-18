#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    // 입력
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // 수열 A의 각 나머지에 대한 카운트
    vector<int> count(7, 0);
    for (int i = 0; i < n; ++i) {
        count[a[i] % 7]++;
    }

    ll bSum = 0; // b 값 누적 합의 나머지 (mod 7)

    for (int i = 0; i < m; ++i) {
        bSum = (bSum + b[i]) % 7; // bSum을 7로 나눔
        int targetRemainder = (7 - bSum) % 7;

        // targetRemainder에 해당하는 값이 존재하면 제거
        if (count[targetRemainder] > 0) {
            count[targetRemainder] = 0; // 해당 나머지 값 제거
        } else {
            // 제거할 수 없다면 bSum 복구
            bSum = (bSum - b[i] + 7) % 7;
        }
    }

    // 최종 결과 계산
    vector<ll> result;
    for (int i = 0; i < n; ++i) {
        if (count[a[i] % 7] > 0) { // 나머지가 남아있으면 추가
            result.push_back((a[i] + accumulate(b.begin(), b.end(), 0LL) % MOD) % MOD);
        }
    }

    // 출력
    cout << result.size() << "\n";
    for (ll val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
