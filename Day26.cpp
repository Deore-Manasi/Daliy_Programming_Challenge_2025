//// Cycle Detection in an Undirected Graph using DFS
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    bool dfs(int node, int parent, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited)) return true;
            }
            else if (neighbor != parent) {
                return true; // cycle detected
            }
        }
        return false;
    }

    bool containsCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    // Example 1
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 0);
    cout << (g1.containsCycle() ? "true" : "false") << endl; // true

    // Example 2
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    cout << (g2.containsCycle() ? "true" : "false") << endl; // false

    

    return 0;
}
