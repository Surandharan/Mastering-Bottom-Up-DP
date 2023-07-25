#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = size(nums), sum = accumulate(begin(nums), end(nums), 0);
        if(sum & 1) return false;
        sum /= 2;

        int dp[n + 1][sum * 2 + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        dp[0][nums[0]] = 1;

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= sum; j++){

                int pick = 0, notPick = 0;

                // pick
                if(nums[i] <= j) pick = dp[i - 1][j - nums[i]];

                // not pick
                notPick = dp[i - 1][j];

                dp[i][j] = pick or notPick;
            }
        }

        return dp[n - 1][sum];
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    cout<<sol.isSubsetSum(v);
}