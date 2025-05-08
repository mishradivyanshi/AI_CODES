#include <iostream>
using namespace std;

const int V = 4;  // Number of vertices

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0; // backtrack
        }
    }
    return false;
}

void printSolution(int color[]) {
    cout << "Solution Exists:\nVertex : Color\n";
    for (int i = 0; i < V; i++)
        cout << "   " << i << "    :   " << color[i] << endl;
}

bool graphColoring(bool graph[V][V], int m) {
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(color);
    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}
