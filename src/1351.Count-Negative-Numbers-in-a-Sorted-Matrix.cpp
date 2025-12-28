class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        int sum=0;
        for(int i=n-1, j=0; i>=0 & j<m;){
            const bool neg=grid[i][j]<0;
            sum+=(-neg & (m-j));
            i-=neg;
            j+=!neg;
        }
        return sum;
    }
};
