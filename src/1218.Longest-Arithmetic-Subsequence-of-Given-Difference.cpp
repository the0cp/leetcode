class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=0;
        unordered_map<int,int>dp;
        for(int x:arr){
            dp[x]=dp[x-difference]+1;
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};
