class Solution {
private: int result;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i=cost.size();
        int dp[2];
        dp[0]=0;
        dp[1]=0;
        for(int i=2; i<=cost.size(); i++){
            result=min(dp[1]+cost[i-1],dp[0]+cost[i-2]);
            dp[0]=dp[1];
            dp[1]=result;
        }
        return result;
    }
};