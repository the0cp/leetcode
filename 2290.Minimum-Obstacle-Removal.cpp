class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        struct node{int x, y;};
        vector<vector<int>>dir={{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        deque<node>q;
        q.push_front(node{0,0});
        dis[0][0]=0;
        while(q.size()){
            auto u=q.front();
            q.pop_front();
            int x=u.x;
            int y=u.y;
            for(int i=0; i<4; i++){
                int xx=x+dir[i][0];
                int yy=y+dir[i][1];
                if(xx>=0 && yy>=0 && xx<m && yy<n && dis[xx][yy]==INT_MAX){
                    dis[xx][yy]=dis[x][y]+grid[xx][yy];
                    if(grid[xx][yy])    q.push_back(node{xx,yy});
                    else    q.push_front(node{xx,yy});
                }
            }
        }
        return dis[m-1][n-1];
    }
};
