class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        unordered_map<int,int>suffix;
        unordered_map<int,int>prefix;
        for(auto n:nums)    suffix[n]++;
        long long ans=0;
        for(auto n:nums){
            suffix[n]--;
            ans+=(long long)prefix[2*n]*suffix[2*n];
            prefix[n]++;
        }
        return ans%mod;
    }
};
