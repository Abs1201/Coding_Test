#include <bits/stdc++.h>
using namespace std;

int main(void){
    array<int,2> ar = {1,2}, ar2 = {4,-1};
    set<array<int,2>> s;
    s.insert(ar);
    s.insert(ar2);
    s.insert({2,-2});
    for(auto it=s.begin(); it!=s.end(); it++){
        // for(auto& e: *it){
        //     cout << e << " ";
        // }
        for(int i=0; i<(*it).size(); i++){
            cout <<(*it)[i] << " ";
        }
        cout << endl;
    }


    return 0;
}