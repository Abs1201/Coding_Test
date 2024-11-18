#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=1e9+7;
const int mxN=1e5;

int n,m;
ll a[mxN], b, c[mxN], d[mxN];

int main(void){
    cin >> n >> m;
    map<int,int> aMap;
    for(int i=0; i<n; i++){
        cin >> a[i];
        c[i]=a[i]%7;
        aMap[c[i]]++;
    }

    ll bSum=0;
    int nCount=n;
    for(int i=0;i<m; i++){
        cin>>b;
        bSum+=b;
        nCount-=aMap[(7-(bSum%7))%7];
        // cout << "~~: " << (7-(bSum%7))%7 << endl;
        if(nCount>0){
            aMap[(7-(bSum%7))%7]=0;
        }
        else{ // nCount==0
            nCount+=aMap[(7-(bSum%7))%7];
            bSum-=b;
        }
        bSum%=M;

    }
    // cout << "bsum: " << bSum << endl;

    cout << nCount << endl;
    for(int i=0; i<n; i++){
        if(aMap[c[i]]>0){
            cout << (a[i]+bSum)%M << ' ';
        }
    }
    

    



    return 0;
}