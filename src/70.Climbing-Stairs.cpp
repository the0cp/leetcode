class Solution {
private: int sum=1;
public:
    int climbStairs(int n) {
        int dp[2];
        dp[0]=1;
        dp[1]=1;
        for(int i=1; i<n; i++){
            sum=dp[0]+dp[1];
            dp[0]=dp[1];
            dp[1]=sum;
        }
        return sum;
    }
};