#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getBigger(int& a, int& b) {
    return a > b ? a : b;
}


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    if (triangle.size() == 0) {
        return 0;
    }
    else if (triangle.size() == 1) {
        return triangle[0][0];
    }

    
    vector<vector<int>> Sum = triangle;


    int seq;
    for (seq = 1; seq < triangle.size(); seq++) {
        for(int i = 0; i <= seq; i++){
            if (i == 0) {
                Sum[seq][i] += Sum[seq-1][i];
            }
            else if (i == seq) {
                Sum[seq][i] += Sum[seq - 1][i-1];
            }
            else {
                Sum[seq][i] += getBigger(Sum[seq - 1][i-1], Sum[seq - 1][i]);
            }
            
        }
    }

    for (int i = 0; i < triangle.size(); i++) {
        answer = getBigger(answer, Sum[triangle.size() - 1][i]);
    }

    return answer;
}
