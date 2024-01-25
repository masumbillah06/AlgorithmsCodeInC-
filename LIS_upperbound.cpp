#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& nums) {
    vector<int> dp;
    for (int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    return dp.size();
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
