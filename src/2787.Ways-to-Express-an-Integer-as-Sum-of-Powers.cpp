class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int>dp(n+1);
        dp[0]=1;
        int max=0;
        for(int i=1; pow(i,x)<=n; i++)  max=i;
        for(int i=1; i<=max; i++){
            int p=pow(i,x);
            for(int j=n; j>=p; j--) dp[j]=(dp[j]+dp[j-p])%(int)(1e9+7);
        }
        return dp[n];
    }
};
