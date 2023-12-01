#include <iostream>
#include <vector>
#include <stack>

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

    bool isEulerian() {
        if (!isConnected()) {
            return false;
        }

        for (int i = 0; i < V; ++i) {
            if (adjacencyList[i].size() % 2 != 0) {
                return false;
            }
        }

        return true;
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        dfs(0, visited);

        for (bool vertexVisited : visited) {
            if (!vertexVisited) {
                return false;
            }
        }

        return true;
    }

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adjacencyList[v]) {
            if (!visited[u]) {
                dfs(u, visited);
            }
        }
    }

    void findEulerianCycle() {
        if (!isEulerian()) {
            cout << "Khong ton tai chu trinh Euler.\n";
            return;
        }

        stack<int> eulerianCycle;
        vector<vector<int>> tempAdjList = adjacencyList;

        int startVertex = 0;
        eulerianCycle.push(startVertex);

        while (!eulerianCycle.empty()) {
            int currentVertex = eulerianCycle.top();

            if (!tempAdjList[currentVertex].empty()) {
                int nextVertex = tempAdjList[currentVertex].back();
                tempAdjList[currentVertex].pop_back();

                eulerianCycle.push(nextVertex);
            } else {
                cout << eulerianCycle.top() << " ";

                eulerianCycle.pop();
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

    cout << "Chu trinh Euler: ";
    graph.findEulerianCycle();

    return 0;
}

