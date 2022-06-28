// lv2 //https://programmers.co.kr/learn/courses/30/lessons/1835

#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

char kakaoFriends[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

inline int abs(int n) {
    return (n > 0) ? n : -n;
}

inline int normalizeAlphabet(char c) {
    assert(c >= 'A' && c <= 'Z');
    return c - 'A';
}
inline int normalizeDigit(char c) {
    assert(c >= '0' && c <= '9');
    return c - '0';
}

inline void getIndexes(int(*index)[26], const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        (*index)[normalizeAlphabet(str[i])] = i;
    }
}

int solution(int n, vector<string> data) {
    char str[] = "ACFJMNRT";
    int index[26] = { 0 };
    getIndexes(&index, str);

    for (int i = 0; i < 26; i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    int perm[] = { 0,1,2,3,4,5,6,7 };

    int answer = 0;


    cout << data[0][0] << " " << normalizeAlphabet(data[0][0]) << endl;
    cout << data[0][2] << " " << normalizeAlphabet(data[0][2]) << endl;
    int tmp1 = normalizeAlphabet(data[0][0]);
    int tmp2 = normalizeAlphabet(data[0][2]);



    do {
        bool flag = 1;
        for (string& cond : data) {
            const int name1 = normalizeAlphabet(cond[0]);
            const int name2 = normalizeAlphabet(cond[2]);
            const int num = normalizeDigit(cond[4]);
            const char op = cond[3];

            const int distance = abs(perm[index[name1]] - perm[index[name2]]) - 1;

            if (op == '>' && !(distance > num)) flag = false;
            if (op == '=' && !(distance == num)) flag = false;
            if (op == '<' && !(distance < num)) flag = false;

            if (flag == false)
            {
                break;
            }
        }
        if (flag)
        {
            answer++;
        }
    } while (next_permutation(perm, perm + 8));

    return answer;
}

int main(void) {

    vector<string> data = { "M~C<2", "C~M>1" };
    int result = solution(2, data);

    cout << result;

    return 0;
}