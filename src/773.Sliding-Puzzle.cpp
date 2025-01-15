class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        int step=0;

        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start.push_back(board[i][j]+'0');
            }
        }
        vector<vector<int>>neighbor = {
            {1,3},
            {0,4,2},
            {1,5},
            {0,4},
            {3,1,5},
            {4,2}
        };
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        
        while(!q.empty()){
            int qsize=q.size();
            for(int i=0; i<qsize; i++){
                string cur=q.front();
                q.pop();
                if(cur==target) return step;
                int index=0;
                for(; cur[index]!='0'; index++);
                for(int e : neighbor[index]){
                    string new_board = cur;
                    swap(new_board[index], new_board[e]);
                    if(!visited.count(new_board)){
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
