#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1); 
    int max_length = 1; 

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        max_length = max(max_length, dp[i]); 
    }
    return max_length; 
}

int main() {
    int n; cin >> n;
    set<int> st;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        st.insert(x);
    }
    vector<int> nums;
    for(auto &it: st) nums.push_back(it);
    sort(nums.begin(), nums.end());
    int length = lis(nums);
    cout << length << endl;
    return 0;
}
