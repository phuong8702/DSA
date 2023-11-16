#include <iostream>

using namespace std;

int longestCommonSubsequence(int a[], int m, int b[], int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    const int maxSize = 100;
    int m, n;

    cout << "Enter the size of array a: ";
    cin >> m;

    int a[maxSize];
    cout << "Enter the elements of array a: ";
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    cout << "Enter the size of array b: ";
    cin >> n;

    int b[maxSize];
    cout << "Enter the elements of array b: ";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int lengthLCS = longestCommonSubsequence(a, m, b, n);

    cout << "Length of Longest Common Subsequence: " << lengthLCS << endl;

    return 0;
}

