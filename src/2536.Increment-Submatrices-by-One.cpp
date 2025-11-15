class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>array(n, vector<int>(n,0));
        for(auto&q:queries){
            array[q[0]][q[1]]++;
            if(q[2]+1<n)
                array[q[2]+1][q[1]]--;
            
            if(q[3]+1<n)
                array[q[0]][q[3]+1]--;

            if(q[2]+1<n&&q[3]+1<n)
                array[q[2]+1][q[3]+1]++;
        }
        for(int i=1; i<n; i++){
            array[0][i]+=array[0][i-1];
        }
        for(int i=1; i<n; i++){
            array[i][0]+=array[i-1][0];
            for(int j=1; j<n; j++){
                array[i][j]+=array[i][j-1]+array[i-1][j]-array[i-1][j-1];
            }
        }
        return array;
    }
};
