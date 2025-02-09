class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n=nums.size();
            unordered_map<int,int>cnt;
            long long sum=0;
            for(int i=0; i<n; i++){
                sum+=cnt[i-nums[i]];
                cnt[i-nums[i]]++;
            }
            return (long long)n*(n-1)/2-sum;
        }
    };