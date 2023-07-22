#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // dp[i][j] is the minimum path sum from (0,0) to (i,j) cell

    int minPathSum(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        vector<vector<int>> dp(m, vector<int> (n));
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 and j == 0)) continue;
                int top = (i - 1 >= 0) ? dp[i - 1][j] : 1e6;
                int left = (j - 1 >= 0) ? dp[i][j - 1] : 1e6;
                dp[i][j] = min(top, left) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main(){
    Solution sol;

    int n, m;
    cin >> n, m;
    vector<vector<int>> grid(n, vector<int> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>grid[i][j];
    cout<<sol.minPathSum(grid);
    return 0;
}