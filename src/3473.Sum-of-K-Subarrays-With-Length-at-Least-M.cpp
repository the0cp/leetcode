class Solution {
public:
    int maxSum(std::vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++) prefix[i+1] = prefix[i]+nums[i];
        vector<vector<long long>>dp(n+1, vector<long long>(k+1, LLONG_MIN));
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int j=1; j<=k; j++){
            long long best = LLONG_MIN;
            for(int i=m; i<=n; i++) {
                if(dp[i-m][j-1] != LLONG_MIN) {
                    best = max(best, dp[i-m][j-1]-prefix[i-m]);
                }
                if(best != LLONG_MIN) dp[i][j] = max(dp[i - 1][j], prefix[i] + best);
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][k];
    }
};
