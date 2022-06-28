// lv1 https://programmers.co.kr/learn/courses/30/lessons/67256


#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int abs(int n) { return (n < 0) ? -n : n; }

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int locationL = 7;
    int locationR = 7;
    int locationTmp;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            locationL = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            locationR = numbers[i] - 2;
        }
        else {
            locationTmp = numbers[i];
            int gap1 = abs(locationTmp - locationL); // 2-8 = -6
            int gap2 = abs(locationTmp - locationR); // 2-1 = 1
            if (hand == "right") {
                if ((gap1 - gap2) < 0) {
                    answer += 'L';
                    locationL = numbers[i];
                }
                else {
                    answer += 'R';
                    locationR = numbers[i];
                }
            }
            else {
                if ((gap1 - gap2) > 0) {
                    answer += 'R';
                    locationR = numbers[i];
                }
                else {
                    answer += 'L';
                    locationL = numbers[i];
                }
            }
        }
        cout << "L:" << locationL << " R: " << locationR << endl;
    }
    return answer;
}

int main(void) {

    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";

    cout << solution(numbers, hand);


    return 0;
}
