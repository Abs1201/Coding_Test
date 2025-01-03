#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long min_cost_to_meet(int N, int A, int B, int C, int D, vector<pair<int, int>>& positions) {
    // x와 y 좌표를 각각 분리하여 저장
    vector<int> x_coords(N), y_coords(N);
    
    for (int i = 0; i < N; i++) {
        x_coords[i] = positions[i].first;
        y_coords[i] = positions[i].second;
    }
    
    // x, y 좌표 각각에 대해 중앙값을 구하기 위해 정렬
    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());
    
    // 중앙값 선택
    int median_x = x_coords[N / 2];
    int median_y = y_coords[N / 2];
    
    long long total_cost = 0;
    
    // 중앙값으로 이동할 때의 체력 소모 계산
    for (int i = 0; i < N; i++) {
        int x = positions[i].first;
        int y = positions[i].second;
        
        // x 좌표 이동에 따른 체력 소모
        if (x < median_x) total_cost += (median_x - x) * A;
        else if (x > median_x) total_cost += (x - median_x) * B;
        
        // y 좌표 이동에 따른 체력 소모
        if (y < median_y) total_cost += (median_y - y) * C;
        else if (y > median_y) total_cost += (y - median_y) * D;
    }
    
    return total_cost;
}

int main() {
    // 입력 받기
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    
    vector<pair<int, int>> positions(N);
    for (int i = 0; i < N; i++) {
        cin >> positions[i].first >> positions[i].second;
    }
    
    // 해결 함수 호출
    cout << min_cost_to_meet(N, A, B, C, D, positions) << endl;
    
    return 0;
}
