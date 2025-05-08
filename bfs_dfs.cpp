#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100; 
vector<int> adj[MAX];
bool visited[MAX];



void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

// void dfs(int node){
//     visited[node]=true;
//     cout<<node<<"";
//     for(int neighbour :adj[node]){
//         if(!visited[node]){
//             dfs(neighbour);
//         }
//     }
// }

void BFS(int start) {
    queue<int> q;

    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// void bfs(int start){
//     queue<int>q;
//     for(int i=0;i<MAX;i++){
//            visited[i]=false;
//     }
//     visited[start]=true;
//     q.push(start);
//     while(!q.empty()){
//         int node=q.front();
//         q.pop();
//         cout<<node<<" ";

//         for(int neighbour:adj[node]){
//             if(!visited]){
                   
//             }
//         }
//     }
// }

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    cout << "Enter edges (u v) for an undirected graph:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int start;
    cout << "\nEnter starting node for DFS: ";

    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    cin >> start;
    cout << "DFS traversal: ";
    DFS(start);
    cout << endl;

    cout << "Enter starting node for BFS: ";
    cin >> start;
    cout << "BFS traversal: ";
    BFS(start);
    cout << endl;

    return 0;
}
