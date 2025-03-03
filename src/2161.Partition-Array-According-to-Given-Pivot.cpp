class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>res(nums.size(),0);
        int left=0, right=nums.size()-1;
        for(int i=0,j=nums.size()-1; i<nums.size()&&j>=0; i++,j--){
            if(nums[i]<pivot){
                res[left]=nums[i];
                left++;
            }
            if(nums[j]>pivot){
                res[right]=nums[j];
                right--;
            }
        }
        for(;left<=right;left++)    res[left]=pivot;
        return res;
    }
};
