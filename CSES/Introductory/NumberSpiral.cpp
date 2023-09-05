#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

    int n;
    cin >> n;
    ll ans;
    for(int i = 0; i < n ; i++){
        int y , x;
        cin >> y >> x;
        ll z, z2, gap;
        z = max(y,x);
        z2 = (z-1)*(z-1);
        gap = abs(y-x);
        if(z % 2 == 1){
            if(z==x){
                ans=z2+z+gap;
            }
            else{
                ans=z2+z-gap;
            }
        }
        else{
            if(z==y){
                ans=z2+z+gap;
            }
            else{
                ans=z2+z-gap;
            }
        }
        cout << ans << endl;
    }
    



    return 0;
}