#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dirs{{-2, -1}, {-1, -2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

    double knightProbability(int n, int k, int row, int column) {
        vector dp(k + 1, vector (n, vector<double> (n)));
        dp[0][row][column] = 1;

        for(int moves = 1; moves <= k; moves++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(auto &d : dirs){
                        int previ = i - d[0];
                        int prevj = j - d[1];

                        if(previ >= 0 and previ < n and prevj >= 0 and prevj < n){
                            dp[moves][i][j] += dp[moves - 1][previ][prevj] / 8;
                        }
                    }
                }
            }
        }

        double total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                total += dp[k][i][j];
            }
        }
        return total;
    }
};

int main(){
    Solution sol;

    int n, k, row, column;
    cin >> n >> k >> row >> column;
    double probability = sol.knightProbability(n, k, row, column);
    cout << "The probability that the knight remains on the board after " << k << " moves is: " << probability << endl;
    return 0;
}