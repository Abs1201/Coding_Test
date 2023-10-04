#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e6;
ll n;


int main(void){
    cin >> n;
    
    ll sum=n*(n+1)/2;
    if(sum&1){
        cout << "NO";
        return 0;
    }
    //if 7 -> 28 -> 14
    // 7,6,1
    //
    int sum2=sum/2;
    set<int> a;
    set<int> b;
    for(int i=1; i<=n; i++){
        b.insert(i);
    }
    for(int i=n; i>=0; i--){
        if(sum2-i>0){
            a.insert(i);
            sum2-=i;
        }
        else{
            //sum2=1, i=5
            if(sum2!=0){
                a.insert(sum2);
            }
            break;
        }
    }
    for(int u: a){
        b.erase(u);
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for(int u: a){
        cout << u << " ";
    }
    cout << endl;
    cout << b.size() << endl;
    for(int u: b){
        cout << u << " ";
    }
    


    return 0;
}