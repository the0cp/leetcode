class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        q.emplace(entrance[0],entrance[1]);
        int steps=0;
        while(!q.empty()){
            steps++;
            int len=q.size();
            for(int i=0; i<len; i++){
                auto p=q.front();
                q.pop();
                for(auto d:dir){
                    int nx=p.first+d[0];
                    int ny=p.second+d[1];
                    if(0<=nx && nx<m && 0<=ny && ny<n && maze[nx][ny]=='.'){
                        if((nx==0 || nx==m-1 || ny==0 || ny==n-1) && (nx!=entrance[0] || ny!=entrance[1])){
                            return steps;
                        }
                        maze[nx][ny]='+';
                        q.emplace(nx,ny);
                    }
                }
            }
        }
        return -1;
    }
};
