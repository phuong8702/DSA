#include <iostream>
#include <vector>
#include <queue>

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
    }

    void bfs(int source) {
        vector<bool> visited(V, false);
        vector<int> distance(V, 0);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjacencyList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }

        cout << "Thu tu to po: ";
        for (int i = 0; i < V; ++i) {
            cout << i << "(" << distance[i] << ") ";
        }
        cout << endl;
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

    int source;
    cout << "Nhap dinh nguon: ";
    cin >> source;

    graph.bfs(source);

    return 0;
}

