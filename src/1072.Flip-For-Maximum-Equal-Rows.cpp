class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();    int n=matrix[0].size();
        int result=0;
        unordered_map<string, int> mp;
        for(int i=0; i<m; i++){
            string s=string(n,'0');
            for(int j=0; j<n; j++){
                s[j]='0'+(matrix[i][j]^matrix[i][0]);
                // flip matrix[i][0]==1 row to get a pattern.
            }
            mp[s]++;
        }

        for(auto&[k,v] :mp){
            result=max(result, v);
        }
        return result;
    }
};
