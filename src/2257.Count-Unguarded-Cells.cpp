class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int mp[m][n];
        memset(mp, 0, sizeof(mp));
        int result=0;
        for(auto& e:guards)   mp[e[0]][e[1]]=2;
        for(auto& e:walls)    mp[e[0]][e[1]]=2;
        int directions[5]={-1, 0, 1, 0, -1};
        for(auto& e:guards){
            for(int i=0; i<4; i++){
                int x=e[0]; int y=e[1];
                int dx=directions[i];   int dy=directions[i+1];
                while(x+dx>=0 && x+dx<m && y+dy>=0 && y+dy<n && mp[x+dx][y+dy]<2){
                    x+=dx;  y+=dy;
                    mp[x][y]=1;
                }
            }
        }
        for(int i = 0; i < m; i++) result+=count(mp[i], mp[i]+n, 0);
        return result;
    }
};
