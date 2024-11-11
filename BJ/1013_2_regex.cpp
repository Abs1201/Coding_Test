#include <iostream>
#include <regex>

using namespace std;

int main() {
    int t;
    cin >> t;
    regex pattern("(100+1+|01)+");

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        if (regex_match(s, pattern)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
