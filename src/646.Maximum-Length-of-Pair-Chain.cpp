class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(n,1);
        int ans=1;
        sort(pairs.begin(), pairs.end(), [](const vector<int>&a, const vector<int>&b){return a[0]<b[0];});
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j][1]<pairs[i][0]) dp[i]=max(dp[i], dp[j]+1);
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
