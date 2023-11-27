#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<int> dp(n + 1, 0);

    for (int j = 0; j <= n; ++j)
        dp[j] = j;

    for (int i = 1; i <= m; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if (word1[i - 1] == word2[j - 1])
                dp[j] = prev;
            else
                dp[j] = 1 + min({dp[j - 1], dp[j], prev});
            prev = temp;
        }
    }

    return dp[n];
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    int minOps = minDistance(word1, word2);
    cout << "Minimum operations required: " << minOps << endl;

    return 0;
}
