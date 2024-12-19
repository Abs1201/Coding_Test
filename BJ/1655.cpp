#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



int main(void){
    int n;
    cin >> n;
    //max, min heap
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    vector<int> ans;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(i==0) pq1.push(a);
        else if(i==1){
            if(pq1.top()>a){
                int tmp=pq1.top();
                pq1.pop();
                pq1.push(a);
                pq2.push(tmp);
            }
            else{
                pq2.push(a);
            }
        }
        else{
            int t1=pq1.top();
            int t2=pq2.top();
            int s1=pq1.size();
            int s2=pq2.size();
            if(s1>s2){
                if(a<t2 && a>t1){
                    pq2.push(a);
                }
                else if(a<t2){
                    pq1.push(a);
                    pq1.pop();
                    pq2.push(t1);
                }
                else{
                    pq2.push(a);
                }
            }
            else{ // ==
                if(a<t2){
                    pq1.push(a);
                }
                else{
                    pq2.push(a);
                    pq2.pop();
                    pq1.push(t2);
                }
            }
        }
        ans.push_back(pq1.top());
    }

    for(auto& e: ans){
        cout << e << endl;
    }



    return 0;
}