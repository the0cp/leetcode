class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, LLONG_MIN)));
        
        if (coins[0][0] < 0){
            dp[0][0][1] = 0;
        }
        dp[0][0][2] = coins[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k <= 2; k++){
                    if(dp[i][j][k] == LLONG_MIN) continue;
                    if(j + 1 < n){
                        if(coins[i][j + 1] < 0 && k > 0){
                            dp[i][j + 1][k - 1] = max(dp[i][j + 1][k - 1], dp[i][j][k]);
                        }
                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + coins[i][j + 1]);
                    }
                    
                    if(i + 1 < m) {
                        if(coins[i + 1][j] < 0 && k > 0) {
                            dp[i + 1][j][k - 1] = max(dp[i + 1][j][k - 1], dp[i][j][k]);
                        }
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + coins[i + 1][j]);
                    }
                }
            }
        }
        long long res = LLONG_MIN;
        for(int k = 0; k <= 2; k++) {
            if(dp[m-1][n-1][k] != LLONG_MIN) {
                res = max(res, dp[m-1][n-1][k]);
            }
        }
        return (int)res;
    }
};
