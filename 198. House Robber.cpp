#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // dp[i] -> max money robbed till i

    int rob(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return nums[0];
        vector<int> dp(n);

        // base case
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i] + ((i == 1) ? 0 : dp[i - 2]), dp[i - 1]);
        }

        return dp[n - 1];
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