#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // dp[i] -> maximum amount of money that can be stashed from starting house till ith house
    int solve(vector<int> &nums, int s, int e){
        int n = size(nums);
        vector<int> dp(n);
        dp[s] = nums[s];

        for(int i = s + 1; i < e; i++){
            int prev, prev2 = 0;
            prev = dp[i - 1];
            if(i - 2 >= 0) prev2 = dp[i - 2] + nums[i];
            dp[i] = max(prev, prev2);
        } 

        return dp[e - 1];

    }

    int rob(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return nums[0];
        return max(solve(nums, 0, n - 1), solve(nums, 1, n));
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    cout<<sol.rob(v);
    return 0;
}