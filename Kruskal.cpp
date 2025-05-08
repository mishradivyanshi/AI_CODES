#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5;
int parent[N];
int rankArr[N];

// Find parent with path compression
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// int find(int x){
//     if(parent[x]==x) return x;
//     return parent[x] = find(parent[x]);
// }


// Union by rank
void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (rankArr[a] < rankArr[b]) {
        parent[a] = b;
    } else if (rankArr[a] > rankArr[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rankArr[a]++;
    }
}



int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector< pair<int, pair<int, int>> > edges;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    // Initialize DSU
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int mst_weight = 0;
    vector< pair<int, int> > mst_edges;

    for (int i = 0; i < edges.size(); i++) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (find(u) != find(v)) {
            union_set(u, v);
            mst_weight += w;
            mst_edges.push_back({u, v});
        }
    }

    cout << "\nMST total weight: " << mst_weight << endl;
    cout << "Edges in the MST:\n";
    for (int i = 0; i < mst_edges.size(); i++) {
        cout << mst_edges[i].first << " - " << mst_edges[i].second << endl;
    }

    return 0;
}
