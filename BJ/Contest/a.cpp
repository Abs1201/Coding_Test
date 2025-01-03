#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


int main() {
    int r,c;
    int a, b;
    cin >> r >> c >> a >> b;
    vector<vector<int>> v(c);
    // start with 0
    int tmp = b;
    bool pass = 1;
    for(int i=0; i<r; i++){
        if(c>=i){
            tmp-=i;
            if(tmp<0){
                pass=0;
                break;
            }
        }
        else{
            pass=0;
            break;
        }
    }
    if(pass){



        exit(0);
    }

    // start with 1
    tmp = b;
    pass =1;
    for(int i=0; i<r; i++){
        if(c>=i+1){
            tmp-=i+1;
            if(tmp<0){
                pass=0;
                break;
            }
        }
        else{
            pass=0;
            break;
        }
    }
    if(pass){
        

        exit(0);
    }

    cout << -1;

    return 0;
}
