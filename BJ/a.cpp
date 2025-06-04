#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 비교 후 다른 문자는 *A/T* 형식으로 저장
string mergeSequences(const string& a, const string& b) {
    int maxOverlap = 0;
    int bestStart = 0;
    string result;

    // a의 접미사와 b의 접두사를 비교하여 가장 긴 overlap 찾기
    for (int start = 0; start < a.size(); ++start) {
        int len = min((int)a.size() - start, (int)b.size());
        bool matched = true;
        int mismatchCount = 0;

        for (int i = 0; i < len; ++i) {
            if (a[start + i] != b[i]) {
                mismatchCount++;
                if (mismatchCount > 5) { // 너무 다르면 무시
                    matched = false;
                    break;
                }
            }
        }

        if (matched && len > maxOverlap) {
            maxOverlap = len;
            bestStart = start;
        }
    }

    // 앞부분은 그대로 복사
    result += a.substr(0, bestStart);

    // 겹치는 부분 비교하면서 병합
    for (int i = 0; i < maxOverlap; ++i) {
        char ca = a[bestStart + i];
        char cb = b[i];
        if (ca == cb) {
            result += ca;
        } else {
            result += "*";
            result += ca;
            result += "/";
            result += cb;
            result += "*";
        }
    }

    // b의 나머지 뒷부분 붙이기
    result += b.substr(maxOverlap);

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> sequences(n);
    string result="";
    for(int i=0; i<n; i++){
        cin >> sequences[i];
    }
    result = sequences[0];
    for(int i=1; i<n; i++){
        result = mergeSequences(result, sequences[i]);
    }

    cout << result << endl;

    return 0;
}
