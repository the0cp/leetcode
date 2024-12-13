class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>ids(n);
        iota(ids.begin(), ids.end(), 0);
        stable_sort(ids.begin(), ids.end(), [&](int i, int j){return nums[i]<nums[j];});
        long long ans=0;
        vector<bool>flag(n+1, false);
        for(int i:ids){
            if(!flag[i+1]){
                flag[i]=flag[i+1]=flag[i+2]=true;
                ans+=nums[i];
            }
        }
        return ans;
    }
};
