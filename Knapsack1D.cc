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
typedef vector<ll>	    vll;
typedef vector<vi>	    vvi;
typedef vector<vll>	    vvll;
typedef map<int,int>    mii;
typedef map<ll,ll>      mll;
const int mod = 1'000'000'007;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}

int knapsack(vector<int> &values, vector<int> &weights, int capacity) {
    int n = values.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[capacity];
}

void solve(){
    int n;
    cin >> n;
    vi wt(n), val(n);
    fo(i,0,n){
        cin >> val[i];
        cin >> wt[i];
    }
    int num;
    cin >> num;
    vi members(num);
    for(auto &i: members) cin >> i;

    int sum=0;

    for(int i=0; i<num; i++){
        sum = sum+knapsack(val,wt,members[i]);
    }
    cout << sum << endl;
}

int main(){
    fastIO();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
}
