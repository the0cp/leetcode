class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        static constexpr int dx[4] = {1, -1, 0, 0};
        static constexpr int dy[4] = {0, 0, 1, -1};
        int m=grid.size();
        int n=grid[0].size();
        function<void(int,int,int&)>dfs = [&](int x, int y, int& tmp){
            for(int i=0; i<4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0){
                    tmp+=grid[nx][ny];
                    grid[nx][ny]=0;
                    dfs(nx, ny, tmp);
                }
            }
        };
        int res=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]>0){
                    int cur = grid[i][j];
                    grid[i][j] = 0;
                    dfs(i, j, cur);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};