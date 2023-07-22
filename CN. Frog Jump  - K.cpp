#include <bits/stdc++.h> 
using namespace std;

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, 1e8);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i - j < 0) break;
            dp[i] = min(dp[i], abs(height[i] - height[i - j]) + dp[i - j]);
        }
    }

    return dp[n - 1];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    cout<<frogJump(n, k, heights);
    return 0;
}