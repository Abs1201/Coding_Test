#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isoverlap(vector<int> arr, int n) {
    for (int& e : arr) {
        if (n == e)return 1;
    }
    return 0;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int tmp = 0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            tmp = numbers[i] + numbers[j];
            if (isoverlap(answer, tmp) == 0) answer.push_back(tmp);
        }
    }

    sort(answer.begin(), answer.end());


    return answer;
}

int main(void) {

    vector<int> numbers = { 2, 1, 3, 4, 1 };

    vector<int> answer = solution(numbers);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }


    return 0;
}