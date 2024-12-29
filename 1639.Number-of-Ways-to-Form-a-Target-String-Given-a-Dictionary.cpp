class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int mod = 1e9+7;
        int n=words[0].size();
        int m=target.size();
        if(n<m) return 0;
        vector<vector<long long>>dp(n+1, vector<long long>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0]=1;
        vector<vector<int>>vec(n,vector<int>(26,0));
        for(auto&word:words){
            for(int i=0;i<n;i++)    vec[i][word[i]-'a']++;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*vec[i-1][target[j-1]-'a'])%mod;
            }
        }
        return dp[n][m];
    }
};
