class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        long long cur=0LL;
        int cnt=0;
        for(int i=0; i<n-1; i++){
            cur+=nums[i];
            cnt+=(cur>=sum-cur);
        }
        return cnt;
    }
};
