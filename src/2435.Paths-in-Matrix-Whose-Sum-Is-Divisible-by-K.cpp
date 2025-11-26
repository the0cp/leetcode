class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int mod=1e9+7;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0&&j==0)  continue;
                for(int r=0; r<k; r++){
                    int newr=(r+grid[i][j])%k;
                    if(i>0) dp[i][j][newr]=(dp[i][j][newr]+dp[i-1][j][r])%mod;
                    if(j>0) dp[i][j][newr]=(dp[i][j][newr]+dp[i][j-1][r])%mod;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};
