#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<ll>	    vll;
typedef vector<vi>	    vvi;
typedef vector<vll>	    vvll;
const int mod = 1'000'000'007;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}

int knapsack(vector<int> &values, vector<int> &weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    fastIO();
    
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int max_value = knapsack(values, weights, capacity);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}

