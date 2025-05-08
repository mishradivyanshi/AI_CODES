#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0, 0}); // (weight, start node)
    int mst_sum = 0;

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int weight = current.first;
        int node = current.second;

        if (visited[node]) continue;
        visited[node] = true;
        mst_sum += weight;

        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[node][i].first;
            int edgeWeight = adj[node][i].second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Sum of weights of MST: " << mst_sum << endl;

    return 0;
}
