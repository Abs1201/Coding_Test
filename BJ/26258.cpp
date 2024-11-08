#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(void){
    int n;
    cin >> n;
    vector<array<int,2>> v;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    int t;
    cin >> t;
    vector<array<int,2>>::iterator it;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        it = lower_bound(v.begin(), v.end(), a);

        int next = *it.second();
        --it;
        int prev = *it.second();

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



/*
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(void){
    int n;
    cin >> n;
    multiset<array<int,2>> ms;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        ms.insert({a,b});
    }
    int t;
    cin >> t;
    multiset<array<int,2>>::iterator it;
    
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        
        it = ms.lower_bound({a,0});
        
        int u = it-ms.begin();
        cout << ms[u].second() << endl;
        
        // it = lower_bound(v.begin(), v.end(), a);
        // int u= it-v.begin();
        // cout << u << endl;
        // int next = v[u].second();
        // int prev = v[--u].second();

        // if(next>prev){
        //     cout << "1" << endl;
        // }
        // else if(next==prev){
        //     cout << "0" << endl;
        // }
        // else{
        //     cout << "-1" << endl;
        // }
    }

    return 0;
}


*/