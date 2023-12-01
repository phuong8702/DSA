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
        adjacencyList[v].push_back(u);
    }

    bool hasOddCycle() {
        vector<int> color(V, -1);
        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) {
                if (bfs(i, color)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs(int start, vector<int>& color) {
        color[start] = 0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjacencyList[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return true;
                }
            }
        }

        return false;
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

    if (graph.hasOddCycle()) {
        cout << "Do thi chua chu trinh do dai le.\n";
    } else {
        cout << "Do thi la do thi hai mau.\n";
    }

    return 0;
}

