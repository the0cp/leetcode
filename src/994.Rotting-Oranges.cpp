class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        int ans=0;
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0; i<size; i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto& d:dir){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        return fresh==0?ans:-1;
    }
};

