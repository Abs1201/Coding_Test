#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;

// unordered_set<int> s;
vector<int> v;

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        cout << (binary_search(v.begin(), v.end(), a)?1:0) << endl;
        // cout << (s.find(a)!=s.end() ? '1' : '0') << endl;
    }




    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 배열 정렬
    sort(A.begin(), A.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        // 이분 탐색 수행
        cout << (binary_search(A.begin(), A.end(), a) ? 1 : 0) << '\n';
    }

    return 0;
}
