class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(int num:nums){
            int cur = 0;
            for(int x=num; x!=0; x/=10) cur+=x%10;
            if(mp[cur]) ans=max(ans,num+mp[cur]);
            mp[cur]=max(mp[cur],num);
        }
        return ans;
    }
};
