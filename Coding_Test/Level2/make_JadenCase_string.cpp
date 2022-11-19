#include <string>
#include <vector>
#include <iostream>

using namespace std;

// string solution(string s) {
//     //string answer = "";
//     int gap = 'A' - 'a';
//     bool isFirst = 1;

//     for(int i = 0; i < s.length(); i++){
//         if(s[i] <= 'z' && s[i] >= 'a' && isFirst){
//             s[i] += gap;
//             isFirst = 0;
//         }
//         else if(s[i] <= 'Z' && s[i] >= 'A' && !isFirst){
//             s[i] -= gap;
//         }
//         else if(s[i] == ' '){
//             isFirst = 1;
//         }
//         else{
//             isFirst = 0;
//         }
//     }
//     return s;
// }

string solution(string s){
    string answer ="";
    answer += toupper(s[0]);
    for(int i = 1; i < s.length(); i++){
        answer += s[i-1] == ' ' ? toupper(s[i]) : tolower(s[i]);
    }
    return answer; 
}

int main(void){

    string s = "3people unFollowed me";
    string answer = solution(s);
    cout << answer << endl;
    
    
    return 0;
}