class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total=accumulate(nums.begin(), nums.end(), 0LL);
        int rem=total%p;
        if(rem==0)  return 0;

        unordered_map<int, int>mp;
        mp[0]=-1;
        
        int n=nums.size();
        int ans=n;
        long long prefix=0;
        for(int i=0; i<n; i++){
            prefix=(prefix+nums[i])%p;
            int target=(prefix+p-rem)%p;
            if(mp.count(target)){
                int j=mp[target];
                int len=i-j;
                if(len<ans) ans=len;
            }
            mp[prefix]=i;
        }
        if(ans==n)  return -1;
        return ans;
    }
};
