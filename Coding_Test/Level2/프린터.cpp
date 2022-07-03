// lv2 https://programmers.co.kr/learn/courses/30/lessons/42587 프린터

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

template<class T>
inline bool isST(T a, T b) { return (a < b) ? 1 : 0; }

int solution(vector<int> priorities, int location) {
    int answer = 0;
    //pair로 0123 짝지어서 넣고 priorities 반영해서 순서 반영 후 location값 추출
    deque<pair<int, int>> queue(priorities.size());
    for (int i = 0; i < priorities.size(); i++) {
        queue[i] = { i, priorities[i] };
    }

    int count = 0;
    bool check = 1;
    while (count != queue.size()) {
        for (int j = count + 1; j < queue.size(); j++) {
            if (isST(queue[count].second, queue[j].second)) {
                pair<int, int> tmp = queue[count];
                queue.pop_front();
                queue.push_back(tmp);
                check = 0;
                break;
            }
        }
        if (check) count++;
        check = 1;
    }

    for (int i = 0; i < queue.size(); i++) {
        if (location == queue[i].first) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}





int main(void) {

    vector <int> priorities = { 2, 1, 2, 1, 2, 1, 2, 1, 2 };
    int n = 1;



    cout << solution(priorities, n);

    return 0;
}