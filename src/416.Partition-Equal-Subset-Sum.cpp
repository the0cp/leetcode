class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(), nums.end(), 0);
        if(total%2==1)  return false;
        int target=total/2;
        vector<bool>dp(target+1, false);
        dp[0]=true;
        for(int n:nums){
            for(int i=target; i>=n; i--){
                dp[i]=dp[i] || dp[i-n];
                if(dp[target])  return true;
            }
        }
        return dp[target];
    }
};
