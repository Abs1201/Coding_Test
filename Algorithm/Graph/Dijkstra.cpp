#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii; // 정점, 거리

void dijkstra(int start, const vector<vector<pii>>& adj, vector<int>& dist){
    dist[start]=0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if(currentDist>dist[currentNode]) continue;

        for(auto& a: adj[currentNode]){ // auto& a == const pii& neighbor
            int nextNode = a.first;
            int weight = a.second;

            if(dist[currentNode]+weight < dist[nextNode]){
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

}

int main(void){

    int n,m; // nodes, edges
    // cin >> n >> m;
    n=6, m=20;

    vector<vector<pii>> adj(n);
    vector<int> dist(n, INT_MAX);

    // for(int i=0; i<m; i++){
    //     int u,v,w;
    //     cin >> u >> v >> w, --u, --v;
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});
    adj[0].push_back({3,1});
    
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,2});
    
    adj[2].push_back({1,3});
    adj[2].push_back({0,5});
    adj[2].push_back({3,3});
    adj[2].push_back({4,1});
    adj[2].push_back({5,5});
    
    adj[3].push_back({0,1});
    adj[3].push_back({1,2});
    adj[3].push_back({2,3});
    adj[3].push_back({4,1});
    
    adj[4].push_back({3,1});
    adj[4].push_back({2,1});
    adj[4].push_back({5,2});
    
    adj[5].push_back({4,2});
    adj[5].push_back({2,5});
    


    int start;
    // cin >> start, --start;
    start=0;

    dijkstra(start, adj, dist);

    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX){
            cout << "no answer";
        }
        else cout << dist[i] << " ";
    }
    cout << '\n';


    return 0;
}