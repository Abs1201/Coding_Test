#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(int n) {
    int answer = 0;

    string s = "";
    while(n >= 2){
        char c = '0' + n%2;
        s += c;
    }
    s+=1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            if((s[i+1]) == '0'){
                return i;
            }
        }
    }

    return answer;
}

int main(void){

    cout << solution(1) <<endl;

    return 0;
}
//test