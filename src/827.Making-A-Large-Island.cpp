class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        static constexpr int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int n=grid.size();
        vector<int>area;
        auto dfs = [&](auto&& dfs, int i, int j) -> int {
            grid[i][j] = area.size()+2;
            int size = 1;
            for(auto&[dx,dy] : dir){
                int x = i+dx;
                int y = j+dy;
                if(0<=x && x<n && 0<=y && y<n && grid[x][y]==1){
                    size += dfs(dfs, x, y);
                }
            }
            return size;
        };

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) area.push_back(dfs(dfs,i,j));
            }
        }
        if(area.empty())   return 1;
        int ans=0;
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]>0) continue;
                s.clear();
                int sum = 1;
                for (auto& [dx,dy] : dir){
                    int x = i+dx;
                    int y = j+dy;
                    if(0<=x && x<n && 0<=y && y<n && grid[x][y]>0 && s.insert(grid[x][y]).second){
                        sum += area[grid[x][y]-2];
                    }
                }
                ans=max(ans, sum);
            }
        }
        return ans?ans : n*n;
    }
};