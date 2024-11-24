#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> dqu;
    for(int i=0; i<n; i++){
        dqu.push_back(i);
    }

    int dist=0;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        --a;
        auto it = find(dqu.begin(), dqu.end(), a);
        int ap = it-dqu.begin();
        int dui = dqu.end()-it;
        if(ap>dui){
            for(int j=0; j<dui; j++){
                int tmp=dqu.back();
                dqu.pop_back();
                dqu.push_front(tmp);
            }
            dist+=dui;
        }   
        else{
            for(int j=0; j<ap; j++){
                int tmp=dqu.front();
                dqu.pop_front();
                dqu.push_back(tmp);
            }
            dist+=ap;
        }     
        dqu.pop_front();
    }
    cout << dist;


    return 0;
}
