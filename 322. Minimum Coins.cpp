#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e8);
        int n = size(coins);

        // dp[i] represents the minimum amount of coins to sum up to an amount of i
        // base case - for all the amounts that could be made up by single coin, fill with 1
        for(int i = 0; i < n; i++) {
            if(coins[i] <= amount) dp[coins[i]] = 1;
        }
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] < 0) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] >= 1e8 ? -1 : dp[amount];
    }
};
int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<int> matrix(n);
    for(int i = 0; i < n; i++) matrix[i];
    cout<<sol.coinChange(grid);
    return 0;
}