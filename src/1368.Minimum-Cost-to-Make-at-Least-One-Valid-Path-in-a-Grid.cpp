class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int dx[5]={0,1,-1,0,0};
        const int dy[5]={0,0,0,1,-1};
        int m=grid.size();
        int n=grid[0].size();
        deque<pair<int,int>>q;
        q.push_back(make_pair(0,0));
        vector<bool>visited(m*n);
        while(!q.empty()){
            pair<int,int>front=q.front();
            q.pop_front();
            int row=front.second/n;
            int col=front.second%n;
            if(visited[front.second])   continue;
            visited[front.second]=true;
            if(row == m-1 && col == n-1)    return front.first;
            for(int i=1; i<=4; i++){
                int nrow=row+dy[i];
                int ncol=col+dx[i];
                if(nrow<0 || ncol<0 || nrow>=m || ncol>=n)  continue;
                if(grid[row][col]==i) q.push_front(make_pair(front.first, nrow * n + ncol));
                else    q.push_back(make_pair(front.first+1, nrow * n + ncol));
            }
        }
        return 0;
    }
};
