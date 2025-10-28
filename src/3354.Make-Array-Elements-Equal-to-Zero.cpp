class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                int left=accumulate(nums.begin(), nums.begin()+i, 0);
                int right=accumulate(nums.begin()+i+1, nums.end(), 0);
                if(left==right) ans+=2;
                if(left-right==1||right-left==1)    ans++;
            }
        }
        return ans;
    }
};
