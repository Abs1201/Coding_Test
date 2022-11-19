#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

string solution(string s) {
    s += ' ';
    string answer = "";
    int big = numeric_limits<int>::min();
    int small = numeric_limits<int>::max();
    string tmp = "";
    int tmp_i;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            tmp += s[i];
        }
        else{
            tmp_i = stoi(tmp);
            big = max(big, tmp_i);
            small = min(small, tmp_i);
            tmp ="";
        }
    }

    answer += to_string(small);
    answer += ' ';
    answer += to_string(big);

    return answer;
}


int main(void){

    string s = "1 2 -3 4";
    string ans = solution(s);
    cout << ans << endl;

    return 0;
}