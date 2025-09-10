//// Shortest Path in an Unweighted Graph using BFS
#include <iostream>
#include <vector>
#include <queue>
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

    int shortestPath(int start, int end) {
        vector<int> dist(V, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end) return dist[node]; // shortest path found

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { // not visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return -1; // no path
    }
};

int main() {
    // Example 1
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << g1.shortestPath(0, 4) << endl; // 3

    // Example 2
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    cout << g2.shortestPath(0, 2) << endl; // 2

    // Example 3
    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    cout << g3.shortestPath(2, 3) << endl; // -1 (no path)

    return 0;
}
