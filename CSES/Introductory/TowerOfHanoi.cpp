#include <bits/stdc++.h>
using namespace std;
 
const int mxN=16;
int n;
 
void hanoi(vector<array<int,2>>& v, int a, int start=1, int end=3, int sub=2){
    if(a==1){
        v.push_back({start, end});
        return;
    }
    else{
        hanoi(v,a-1,start, sub, end);
        v.push_back({start, end});
        hanoi(v,a-1, sub, end, start);
    }
}
 
 
int main(void){
    
    cin >> n;
    
    vector<array<int,2>> v;
    hanoi(v, n);
    
    cout << v.size() << endl;
    for(array<int, 2> a : v){
        cout << a[0] << " " << a[1] << endl;
    }
    
    return 0;
}