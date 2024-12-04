#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int r,c;
int arr[9][9];
int ans;

int main(void){
    cin >> r >> c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cin >> arr[i][j];
    }



    ans=-1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}