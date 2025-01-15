class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1)    return -1;
        vector<vector<int>>dirs={{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        dis[0][0]=0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>q;
        q.push({0,0,0});
        while(!q.empty()){
            auto [d,x,y]=q.top();
            q.pop();
            if(d>dis[x][y]) continue;   // not the shortest path skip
            if(x==m-1&&y==n-1)  return d;
            for(auto&e:dirs){
                int xx=x+e[0];
                int yy=y+e[1];
                if(xx>=0 && xx<m && yy>=0 && yy<n){
                    int dd=max(d+1, grid[xx][yy]);
                    dd+=(dd-xx-yy)%2;
                    if(dd<dis[xx][yy]){
                        dis[xx][yy]=dd;
                        q.push({dd,xx,yy});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};
