class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left=0;
        int right=nums.size()-1;
        int cnt=0;
        while(left<right){
            if(nums[left]+nums[right]==k){
                left++;
                right--;
                cnt++;
            }
            else if(nums[left]+nums[right]>k)  right--;
            else if(nums[left]+nums[right]<k)  left++;
        }
        return cnt;
    }
};
