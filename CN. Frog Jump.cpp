#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    // dp[i] -> minimum energy required by the frog to reach i-th stone
    
    vector<int> dp(n + 1);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int oneJump = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        int twoJump = i - 2 >= 0 ? abs(heights[i] - heights[i - 2]) + dp[i - 2] : INT_MAX;
        dp[i] = min(oneJump, twoJump);
    }

    return dp[n - 1];
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    cout<<frogJump(n, v);
    return 0;
}