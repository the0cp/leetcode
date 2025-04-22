class Solution {
private:
    map<int, bool>st;
    int num=0;
public:
    void dfs(vector<vector<int>>&rooms, int n){
        st[n]=true;
        num++;
        for(int i=0; i<rooms[n].size(); i++){
            if(!st[rooms[n][i]])    dfs(rooms, rooms[n][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        return rooms.size()==num;    
    }
};
