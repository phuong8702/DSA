#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int start;
    int end;

    Edge(int s, int e) : start(s), end(e) {}
};

class Graph {
private:
    int V;
    vector<Edge> edges; 

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v) {
        edges.push_back(Edge(u, v));
    }

    bool isParallelEdge(Edge edge) {
        vector<vector<int>> tempGraph(V);
        for (const auto& e : edges) {
            if (e.start != edge.start || e.end != edge.end) {
                tempGraph[e.start].push_back(e.end);
                tempGraph[e.end].push_back(e.start);
            }
        }

        vector<bool> visited(V, false);
        dfs(tempGraph, 0, visited);

        return countTrue(visited) == V;
    }

    int countParallelEdges() {
        int parallelEdges = 0;
        for (const auto& edge : edges) {
            if (isParallelEdge(edge)) {
                parallelEdges++;
            }
        }
        return parallelEdges;
    }

    void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : graph[v]) {
            if (!visited[u]) {
                dfs(graph, u, visited);
            }
        }
    }

    int countTrue(const vector<bool>& vec) {
        int count = 0;
        for (bool value : vec) {
            if (value) {
                count++;
            }
        }
        return count;
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

    cout << "So canh song song la: " << graph.countParallelEdges() << endl;

    return 0;
}

