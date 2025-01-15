class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>res;
        int m = grid.size();    
        if (m == 0) return res;
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j += 2){
                    res.push_back(grid[i][j]);
                }
            }else{
                for (int j = n - 1; j >= 0; j--){
                    if (j % 2 == 1){
                        res.push_back(grid[i][j]);
                    }
                }
            }
        }
        return res;
    }
};
