class Solution {
public:
    int findLHS(vector<int>& nums) {
        ranges::sort(nums);
        int i=0;
        int j=0;
        int ans=0;
        while(i<nums.size()){
            while(nums[i]-nums[j]>1) j++;
            if(nums[i]-nums[j]==1){
                ans=max(ans, i-j+1);
            }
            i++;
        }
        return ans;
    }
};
