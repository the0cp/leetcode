class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i:nums) mp[i]++;
        vector<int>dp;
        dp.push_back(0);
        for(auto& pair:mp)  dp.push_back(pair.first);
        sort(dp.begin(),dp.end());
        int last=dp[1];
        dp[1]=mp[dp[1]] * dp[1];
        int n=dp.size();
        for(int i=2; i<n; i++){
            if(dp[i]-last==1){
                last=dp[i];
                dp[i]=max(dp[i-1], dp[i-2]+dp[i]*mp[dp[i]]);
            }else{
                last=dp[i];
                dp[i]=dp[i-1]+dp[i] * mp[dp[i]];
            }
        }
        return dp[n-1];
    }
};
