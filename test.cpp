#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define ll long long

long long solution(vector<ll> sequence) {
    ll ans1 = 0, ans2=0;
    int n=sequence.size();
    ll s=-1e5;
    for(int i=0; i<n; i++){
        if(i&1)
            s=max(-sequence[i], -sequence[i]+s);
        else
            s=max(sequence[i], sequence[i]+s);
        ans1=max(s,ans1);
    }
    s=-1e5;
    for(int i=0; i<n; i++){
        if(i&1^1){
            s=max(-sequence[i], -sequence[i]+s);
        }
        else
            s=max(sequence[i], sequence[i]+s);
        ans2=max(s,ans2);
    }
    return max(ans1,ans2);
}

int main(void){
    vector<ll> sequence = {2, 3, -6, 1, 3, -1, 2, 4}; 
    cout << solution(sequence);
    return 0;
}