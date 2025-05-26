#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
#define INF 1e9
const int mxN=1e3;

int v, e, k;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF);

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[node]<d) continue;

        for(auto& edge: graph[node]){
            int nextNode = edge.first;
            int cost = d+edge.second;

            if(cost < dist[nextNode]){
                dist[nextNode] = cost;
                pq.push({cost, nextNode});
            }
        }
    }
}

int gcd(int a, int b){
    while(b!=0){
        int tmp = a%b;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >>a >> b;




	return 0;
}