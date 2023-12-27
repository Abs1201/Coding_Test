#include <iostream>
#include <queue>
#include <functional> // greater, less
using namespace std;

//모든 원소 중에서 가장 큰 값이 Top을 유지하도록, 우선순위가 가장 크도록 설계되어 있다.
//push()
//pop(): 우선순위 큐에서 top의 원소를 제거한다
//top(): 우선순위 큐에서 top에 있는 원소 즉 우선순위가 높은 원소를 반환한다.
//empty()
//size()

int main(void) {

    priority_queue<int> pq;
    pq.push(4);
    pq.push(4);
    pq.push(5);
    cout << "size: " << pq.size() << '\n';

    while (pq.size()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}