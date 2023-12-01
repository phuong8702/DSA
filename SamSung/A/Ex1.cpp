#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> edges;

public:
    Graph(int vertices) : V(vertices) {
        edges.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        edges[u][v] = 1;
        edges[v][u] = 1;
    }

    bool isEulerianCycle() {
        for (int i = 0; i < V; ++i) {
            int degree = 0;
            for (int j = 0; j < V; ++j) {
                degree += edges[i][j];
            }
            if (degree % 2 != 0) {
                return false;
            }
        }
        return true;
    }

    bool isHamiltonianCycle() {
        for (int i = 0; i < V; ++i) {
            int degree = 0;
            for (int j = 0; j < V; ++j) {
                degree += edges[i][j];
            }
            if (degree < V / 2) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int vertices, edges;
    cout << "Nhap so dinh: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Nhap danh sach cac canh theo dinh-dinh: " << endl;
    string input;
    getline(cin, input); 

    cout << "Nhap " << vertices << " canh:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Canh " << i + 1 << ": ";
        getline(cin, input);

        int u, v;
        sscanf(input.c_str(), "%d-%d", &u, &v);

        graph.addEdge(u, v);
    }

    cout << "\nDo thi:\n";
    cout << "Chu trinh Euler: " << (graph.isEulerianCycle() ? "Co" : "Khong") << endl;
    cout << "Chu trinh Hamilton: " << (graph.isHamiltonianCycle() ? "Co" : "Khong") << endl;

    return 0;
}

