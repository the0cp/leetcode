class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2; i<n; i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        int ans=INT_MIN;
        for(int i:dp)   ans=max(i, ans);
        return ans;
    }
};
