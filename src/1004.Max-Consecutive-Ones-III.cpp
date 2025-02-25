class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, maxlen=0, zero=0;
        while(right<nums.size()){
            if(nums[right]==0){
                zero++;
            }
            while(zero>k){
                if(nums[left]==0)zero--;
                left++;
            }
            if(zero<=k){
                int size=right-left+1;
                maxlen=max(maxlen,size);
            }
            right++;
        }
        return maxlen;
    }
};
