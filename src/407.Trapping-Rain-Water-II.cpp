class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty())   return 0;
        const int dx[4]={-1,0,1,0};
        const int dy[4]={0,1,0,-1};
        const int m=heightMap.size();
        const int n=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>>pq;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            pq.push({heightMap[0][i], {0,i}});
            pq.push({heightMap[m-1][i], {m-1,i}});
            visited[0][i] = true;
            visited[m-1][i] = true;
        }
        for(int i=1; i<m-1; i++){
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][n-1], {i,n-1}});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        int water=0;
        while(!pq.empty()){
            auto [height,cell]=pq.top();
            auto [row,col]=cell;
            pq.pop();
            for(int i=0; i<4; i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || visited[nrow][ncol])   continue;
                if(heightMap[nrow][ncol] < height){
                    water+=height-heightMap[nrow][ncol];
                    pq.push({height, {nrow,ncol}});
                }else{
                    pq.push({heightMap[nrow][ncol], {nrow,ncol}});
                }
                visited[nrow][ncol] = true;
            }
        }
        return water;
    }
};
