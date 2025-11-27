class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>minpres(k, LLONG_MAX);
        long long prefix=0;
        long long ans=LLONG_MIN;
        minpres[k-1]=0;
        for(int i=0; i<n; i++){
            prefix+=nums[i];
            long long& minpre=minpres[i%k];
            if(minpre!=LLONG_MAX)   ans=max(ans, prefix-minpre);
            minpre=min(prefix, minpre);
        }
        return ans;
    }
};
