#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        int dp[n + 1][sum + 1];
        memset(dp, 0, sizeof(dp));
        
        // Initialize the dp array
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        dp[0][arr[0]] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= sum; j++){
                // not take
                int notTake = dp[i - 1][j];
                
                // take
                int take = 0;
                if(arr[i] <= j) take = dp[i - 1][j - arr[i]];
                
                dp[i][j] = take or notTake;
            }
        }
        
        return dp[n - 1][sum];
    }
};

int main(){
    Solution sol;
    int n, sum;
    cin>>n>>sum;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    cout<<sol.isSubsetSum(v, sum);
}