class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mp(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = make_pair(i,j);
            }
        }
        vector<int>row(m);
        vector<int>col(n);
        for(int i=0; i<m*n; i++){
            auto cell = mp[arr[i]];
            if(++row[cell.first]==n || ++col[cell.second]==m)   return i;
        }
        return -1;
    }
};