#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[5];
int main(){
    vector<int> v ={1,2,3};
    vector<int>::iterator iter;
    for(iter=v.begin(); iter!=v.end(); iter++){
        cout << *iter << ' ';
    }
    cout << endl;

    cout << *(v.rbegin()) << endl;
    cout << *(v.end()-1) << endl;

    // int arr[5];
    // fill(arr, arr+5, -1);
    // for(int& a: arr){
    //     cout << a << ' ';
    // }
    // cout << endl;
}