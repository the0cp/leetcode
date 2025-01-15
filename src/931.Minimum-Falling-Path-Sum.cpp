class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++)  dp[0][i]=matrix[0][i];
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int left, up, right;

                if(j>0) left=dp[i-1][j-1];
                else    left=INT_MAX;

                up=dp[i-1][j];

                if(j<n-1)   right=dp[i-1][j+1];
                else    right=INT_MAX;

                dp[i][j]=matrix[i][j]+min({left, up, right});
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++)  ans=min(dp[n-1][i], ans);
        return ans;
    }
};
