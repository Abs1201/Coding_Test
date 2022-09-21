#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    vector<int> v1 = { 0,0,1,0,1 };
    vector<int> v2 = { 0,0,0,1,1 };

    for (int i = 0; i < problems.size(); i++) {

    }

    return answer;
}

int main(void) {

    vector<vector<int>> problems = { {10, 15, 2, 1, 2}, {20, 20, 3, 3, 4} };

    int alp = 10, cop = 10;

    cout << solution(alp, cop, problems) << endl;


    return 0;
}
