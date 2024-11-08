#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(void){
    int n;
    cin >> n;
    vector<int> v, v2;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back(a);
		v.push_back(b);
    }
    int t;
    cin >> t;
    vector<int>::iterator it, it2;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        it = lower_bound(v.begin(), v.end(), a);

        int u = it-v.begin();

		int next=v2[u];
		int prev=v2[--u];

        if(next>prev){
            cout << "1" << endl;
        }
        else if(next==prev){
            cout << "0" << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }

    return 0;
}