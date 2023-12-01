#include <iostream>

using namespace std;

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

unsigned long long combination(int V, int E) {
    return factorial(V) / (factorial(E) * factorial(V - E));
}

unsigned long long countGraphs(int V, int E) {
    return combination(V * (V - 1) / 2, E);
}

int main() {
    int V, E;
    
    cout << "Nhap so dinh (V): ";
    cin >> V;

    cout << "Nhap so canh (E): ";
    cin >> E;

    if (E > V * (V - 1) / 2) {
        cout << "So canh nhap vao vuot qua gioi han cua do thi.\n";
        return 1;
    }

    cout << "So do thi vô huong khac nhau co " << V << " dinh va " << E << " canh la: " << countGraphs(V, E) << endl;

    return 0;
}

