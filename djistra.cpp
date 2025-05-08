#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    cout << "Enter edges in format (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        for (auto x : adj[node]) {
            int adjNode = x.first;
            int edW = x.second;

            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[n] == 1e9) {
        cout << "-1\n"; // No path exists
        return 0;
    }

    // Reconstruct path from 1 to n
    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << "Shortest path from 1 to " << n << ": ";
    for (int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}



// int main(){
//     int n;
//     int e;
//     cin>>n>>e;

//     vector<pair<int,int>>adj[n+1];

//     for(int i=0;i<e;i++){
//           int u,v,w;
//           cin>>u>>v>>w;
//           adj[u].push_back({v,w});
//           adj[v].push_back({u,w});
//     }
//     vector<int>dist(n+1,1e9),parent(1e9);
//     for(int i=1;i<=n;i++){
//         parent[i]=i;
//     }
//     dist[1]=0;

//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     pq.push({0,1});
//     while(!pq.empty()){
//         auto it=pq.top();
//         int weight=it.first;
//         int node=it.second;
//         pq.pop();

//         for(auto it:adj[node]){
//             int adjnode=it.first;
//             int adjweight=it.second;
//             if(weight+adjweight<dist[adjnode]){
//                 dist[adjnode]=weight+adjweight;
//                 pq.push({dist[adjnode],adjnode});
//                 parent[adjnode]=node;
//             }
//         }
//     }

//     if(dist[n]==-1){
//         cout<<"-1";
//         return 0;
//     }
//     vector<int>path;
//     int node=n;
//     while(parent[node]!=node){
//         path.push_back(node);
//         node=parent[node]
//     }
//     path.push_back(1);
//     reverse(path.begin(,path.end());



// }
