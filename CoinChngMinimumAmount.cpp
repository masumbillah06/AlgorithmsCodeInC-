#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; 

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int size; cin>>size;
    vector<int> coins(size);
    for(auto &it: coins) cin>>it;
    int amount; cin>>amount;
    int minCoinCount = minCoins(coins, amount);
    if (minCoinCount != -1) {
        cout << "Minimum number of coins required: " << minCoinCount << endl;
    } else {
        cout << "It is not possible to make the amount using given coins." << endl;
    }
    return 0;
}
