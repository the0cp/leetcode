class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)    return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> dp(n, 0);
        // rolling array
        for(int i=0; (i<n) && (obstacleGrid[0][i]==0); i++)   dp[i]=1;
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    dp[j]=0;
                }else if(j!=0){
                    dp[j]+=dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};
