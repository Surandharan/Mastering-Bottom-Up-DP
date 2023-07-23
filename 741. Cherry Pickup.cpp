#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = size(grid);
        int dp[n][n][n];

        // base case
        dp[0][0][0] = grid[0][0];

        // all states
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    // dont needa compute base case again
                    int l = i + j - k;
                    if (l < 0 || l >= n) continue;
                    if(i == 0 and j == 0 and k == 0 and l == 0) {
                        continue;
                    }

                    // if any other the two cells is blocked - invalid state
                    if(grid[i][j] == -1 or grid[k][l] == -1){
                        dp[i][j][k] = -1e9;
                        continue;
                    }

                    // collecting cherries in current cells
                    int c = (i != k) ? grid[i][j] + grid[k][l] : grid[i][j];

                    // finding the best previous cells to move from
                    int op1 = (i > 0 and k > 0) ? dp[i - 1][j][k - 1] + c: -1e9;
                    int op2 = (i > 0 and l > 0) ? dp[i - 1][j][k] + c: -1e9;
                    int op3 = (j > 0 and k > 0) ? dp[i][j - 1][k - 1]+ c: -1e9;
                    int op4 = (j > 0 and l > 0) ? dp[i][j - 1][k] + c: -1e9;

                    // storing in cache
                    dp[i][j][k] = max(max(max(op1, op2), op3), op4);
                }
            }
        }

        // result computed when both traversals reach end point
        return max(0, dp[n - 1][n - 1][n - 1]);
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>grid[i][j];
    cout<<sol.cherryPickup(grid);
    return 0;
}