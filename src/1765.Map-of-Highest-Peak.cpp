class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int m =isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m, vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && ans[nx][ny]==-1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};