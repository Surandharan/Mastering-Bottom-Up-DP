#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    // dp[i][j] is the minimum path sum from (0,0) to (i,j) cell

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = size(triangle), res = triangle[0][0];
        vector<vector<int>> dp(n, vector<int> (n, 1e5));
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++){
            int minVal = 1e5;
            for(int j = 0; j < size(triangle[i]); j++){
                int top = dp[i - 1][j];
                int left = (j - 1 >= 0) ? dp[i - 1][j - 1] : 1e5;
                dp[i][j] = triangle[i][j] + min(top, left);
                minVal = min(dp[i][j], minVal);
            }
            res = minVal;
        }

        return res;
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n
    vector<vector<int>> grid(n, vector<int> (n));
    for(int i = 0; i < n; i++) for(int j = 0; j <= i; j++) cin>>grid[i][j];
    cout<<sol.minimumTotal(grid);
    return 0;
}