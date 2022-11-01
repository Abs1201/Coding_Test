#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

string changeNotation(int n, int k) {
    int q = n, r = 0; // quotient, remainder
    string result = "";
    while (1) {
        r = q % k;
        q = q / k;
        result = (char)(r + 48) + result;
        if (q < k) {
            result = (char)(q + 48) + result;
            break;
        }
    }
    return result;
}



int solution(int n, int k) {
    int answer = 0;

    string s = changeNotation(n, k);
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        cout << i << ": " << tmp << endl;
        if (s[i] == '0') {
            //cout << i << ": " << tmp << endl;
            if (tmp.length() == 0) continue;
            else if (isPrime(stoi(tmp))) answer++;
            tmp = "";
        }
        else { tmp += s[i]; }
    }
    if (tmp.length() == 0) return answer;
    else if (isPrime(stoi(tmp))) answer++;


    return answer;
}

int main(void) {        

    cout << solution(11, 10) << endl;
    //cout << isPrime(stoi("")) << endl;


    return 0;
}
