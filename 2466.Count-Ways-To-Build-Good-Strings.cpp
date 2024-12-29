class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod=1e9+7;
        vector<int>dp(high+1, 0);
        dp[0]=1;
        int ans=0;
        for(int i=1; i<=high; i++){
            dp[i]=((i>=zero?dp[i-zero]:0) + (i>=one?dp[i-one]:0))%mod;
            if(i>=low)  ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};
