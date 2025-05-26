#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<array<int, 3>> house(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> house[i][j];
        }
    }
    


    return 0;
}