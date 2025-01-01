class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)    return 0;
        vector<vector<int>>dp(n,vector<int>(4,0));
        // dp[i][0] shareholding
        // dp[i][1] sold
        // dp[i][2] sell
        // dp[i][3] cooldown
        dp[0][0]-=prices[0];
        for(int i=1; i<n; i++){
            dp[i][0] = max({dp[i-1][0], dp[i-1][3]-prices[i], dp[i-1][1]-prices[i]});
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0]+prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max({dp[n-1][3], dp[n-1][1], dp[n-1][2]});
    }
};
