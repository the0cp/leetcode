class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur=nums[0];
        int ans=nums[0];
        for (int i=1; i<nums.size(); ++i) {
            cur = nums[i]>nums[i-1] ? cur+nums[i] : nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};