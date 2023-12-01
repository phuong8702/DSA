#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjacencyList; 

public:
    Graph(int vertices) : V(vertices) {
        adjacencyList.resize(V);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    bool isEdgeConnected() {
        for (int u = 0; u < V; ++u) {
            for (int v : adjacencyList[u]) {
                if (isBridge(u, v)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBridge(int u, int v) {
        vector<bool> visited(V, false);
        int originalComponents = countComponents(u, visited);

        visited.assign(V, false);
        int newComponents = countComponents(u, v, visited);

        return originalComponents < newComponents;
    }

    int countComponents(int start, vector<bool>& visited) {
        int components = 0;
        for (int u = 0; u < V; ++u) {
            if (!visited[u]) {
                dfs(start, u, visited);
                components++;
            }
        }
        return components;
    }

    int countComponents(int u, int v, vector<bool>& visited) {
        int components = 0;
        visited[u] = true;
        visited[v] = true;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(u, i, visited);
                components++;
            }
        }

        return components;
    }

    void dfs(int start, int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adjacencyList[v]) {
            if (!visited[u] && !(start == v && u == start)) {
                dfs(start, u, visited);
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Nhap so dinh: ";
    cin >> vertices;

    cout << "Nhap so canh: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Nhap " << edges << " canh:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cout << "Canh " << i + 1 << ": ";
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.isEdgeConnected()) {
        cout << "Do thi la do thi lien thong canh.\n";
    } else {
        cout << "Do thi khong lien thong canh.\n";
    }

    return 0;
}

