class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=nums[0];
        int minSum=nums[0];
        int res=abs(nums[0]);
        for(int i=1; i<nums.size(); i++){
            maxSum=max(maxSum+nums[i], nums[i]);
            minSum=min(minSum+nums[i], nums[i]);
            res=max(res, max(abs(maxSum), abs(minSum)));
        }
        return res;
    }
};
