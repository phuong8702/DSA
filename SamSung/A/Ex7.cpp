#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void floodfillDFS(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
    if (!isValid(x, y, image.size(), image[0].size()) || image[x][y] != oldColor) {
        return;
    }

    image[x][y] = newColor;

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        floodfillDFS(image, newX, newY, newColor, oldColor);
    }
}

void floodfill(vector<vector<int>>& image, int x, int y, int newColor) {
    if (isValid(x, y, image.size(), image[0].size())) {
        int oldColor = image[x][y];
        if (oldColor != newColor) {
            floodfillDFS(image, x, y, newColor, oldColor);
        }
    }
}

void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "Nhap so hang cua anh: ";
    cin >> rows;

    cout << "Nhap so cot cua anh: ";
    cin >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    cout << "Nhap gia tri cho tung pixel:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Pixel (" << i << ", " << j << "): ";
            cin >> image[i][j];
        }
    }

    cout << "Anh truoc khi thuc hien floodfill:\n";
    printImage(image);

    int x, y, newColor;
    cout << "Nhap toa do diem bat dau (x, y): ";
    cin >> x >> y;
    cout << "Nhap mau moi: ";
    cin >> newColor;

    floodfill(image, x, y, newColor);

    cout << "Anh sau khi thuc hien floodfill:\n";
    printImage(image);

    return 0;
}

