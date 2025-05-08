#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kahn(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n, 0);

    // Calculate indegree of each node
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    

    queue<int> q;
    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // If topological sort is possible (no cycle)
    if (topo.size() == n) {
        cout << "Topological Order: ";
        for (int node : topo)
            cout << node << " ";
        cout << endl;
    } else {
        cout << "Cycle detected! Topological sort not possible.\n";
    }
}



int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " directed edges (from -> to):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    kahn(n, adj);

    return 0;
}
