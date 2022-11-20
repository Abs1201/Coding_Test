#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s < n){
        answer.push_back(-1);
        return answer;
    }
    int quotient = s/n;
    int remainer = s%n;
    for(int i = 0; i < n; i++){
        answer.push_back(quotient);
    }
    for(int i = 0; i < remainer; i++){
        answer[i] += 1;
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main(void){

    int n = 2;
    int s = 9;
    vector<int> bs = solution(n, s);
    for(auto& e: bs) cout << e << endl;

    return 0;
}