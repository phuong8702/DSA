#include <iostream>
#include <cmath>

using namespace std;

int countDirectedAcyclicGraphs(int V) {
    return pow(V, V - 1);
}

int main() {
    int V;

    cout << "Nhap so dinh (V): ";
    cin >> V;

    int count = countDirectedAcyclicGraphs(V);
    cout << "So do thi co huong phi chu trinh voi " << V << " dinh la: " << count << endl;

    return 0;
}

