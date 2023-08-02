#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = size(matrix), m = size(matrix[0]), res = 0;
        vector<vector<int>> dp(n, vector<int> (m));

        // dp[i][j] denotes the number of squares that can be formed
        // using (i,j) as the bottom-right cell

        // base case - all cells in first column and first row
        // form squares of length 1, if they hold value 1

        for(int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            res += matrix[i][0];
        }

        // starting from 1 since (0,0) was covered previously
        for(int i = 1; i < m; i++){
            dp[0][i] = matrix[0][i];
            res += matrix[0][i];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j]){
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                    res += dp[i][j];
                }
            }
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
    cout<<sol.countSquares(grid);
    return 0;
}