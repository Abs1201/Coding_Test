#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct bchar{
    char c;
    bool b;
    bchar(char c, bool b) : c(c), b(b) {}
    bchar() : c(' '), b(false) {}
    bchar(char c) : c(c), b(false) {}
};


string Merge(const string& a, const string& b){
    string result = "";
    int lenA = a.size();
    int lenB = b.size();
    if (lenA < 10 || lenB < 10) {
        return result;
    }
    vector<string> B;
    for(int i=0; i<lenB; i+=10){
        B.push_back(b.substr(i, 10));
    }
    vector<string> A;
    for(int i=0; i<lenA; i+=10){
        A.push_back(a.substr(i, 10));
    }
    

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
