class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans=1;
        int n=nums.size();
        int interval=k*2;
        sort(nums.begin(), nums.end());
        for(int l=0, r=0; r<n; r++){
            if(nums[r]-nums[l]>interval)    l++;
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};
