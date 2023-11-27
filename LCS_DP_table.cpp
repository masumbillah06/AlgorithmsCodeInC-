#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longest_common_subsequence(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Initializing the DP table with zeros
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Filling the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string X , Y;
    cin >> X >> Y;
    int result = longest_common_subsequence(X, Y);
    int lenofxy = X.size() + Y.size();
    cout << "Length of Longest Common Subsequence: " << result << endl;
    result*=2;
    cout << "Need to remove: " << (lenofxy-result) << "\n";

    return 0;
}
