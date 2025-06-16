class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal=nums[0];
        int res=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>minVal)  res=max(res, nums[i]-minVal);
            else    minVal=nums[i];
        }
        return res;
    }
};
