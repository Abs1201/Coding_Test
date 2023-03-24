#include <string>
#include <vector>
#include <iostream>


using namespace std;

int case1(string s, int index){
    s.swap(i, i+1);
}

int solution(int n) {
    int answer = 0;

    string s = "";
    while(n >= 2){
        char c = '0' + n%2;
        s = c + s;
    }
    s = '1' + s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            if((s[i+1]) == '1'){
                return case1(s, i);
            }
        }
    }

    return answer;
}

int main(void){

    cout << solution(1) <<endl;

    return 0;
}