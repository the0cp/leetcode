class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>col(m);
        vector<int>cur(m);
        int ans=0;
        for(int i=0; i<n; i++){
            int diff=0;
            bool hasX=false;
            for(int j=0; j<m; j++){
                col[j]+=(grid[i][j]=='X'?1:(grid[i][j]=='Y'?-1:0));
                if(grid[i][j]=='X') cur[j]=1;
                diff+=col[j];
                hasX|=cur[j];
                ans+=(diff==0&&hasX);
            }
        }
        return ans;
    }
};
