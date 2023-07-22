#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // dp[i][j] is the minimum falling sum from (0,0) to (i,j) cell

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = size(matrix), res = matrix[0][0];
        vector<vector<int>> dp(n, vector<int> (n, 1e5));

        for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

        for(int i = 1; i < n; i++){
            int minVal = 1e5;
            for(int j = 0; j < size(matrix[i]); j++){
                int top = dp[i - 1][j];
                int left = (j - 1 >= 0) ? dp[i - 1][j - 1] : 1e5;
                int right = (j + 1 < n) ? dp[i - 1][j + 1] : 1e5;
                dp[i][j] = matrix[i][j] + min(right, min(top, left));
                minVal = min(dp[i][j], minVal);
            }
            res = minVal;
        }

        return res;
    }
};

int main(){
    Solution sol;

    int n, m;
    cin >> n, m;
    vector<vector<int>> grid(n, vector<int> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>grid[i][j];
    cout<<sol.minFallingPathSum(grid);
    return 0;
}