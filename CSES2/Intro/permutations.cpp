#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e6;
int n;


int main(void){
    cin >> n;

    if(n==1){
        cout << 1;
        return 0;
    }
    if(n<=3){
        cout << "NO SOLUTION";
        return 0;
    } 
    //2 4 1 3
    for(int i=2; i<=n; i+=2){
        cout << i << " ";
    }
    for(int i=1; i<=n; i+=2){
        cout << i << " ";
    }
    


    return 0;
}