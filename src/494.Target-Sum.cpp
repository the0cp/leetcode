class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum<abs(target) || (sum + target)%2 != 0) return 0;

        int pos = (sum + target) / 2;
        vector<int> dp(pos+1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j=pos; j>=num; j--) {
                dp[j] += dp[j-num];
            }   // Reverse traversal prevents dp[j] from being modified multiple times
        }
        return dp[pos];
    }
};
