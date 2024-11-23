class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[n].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for(int i=0; i<m; i++){
            int index=0;
            while(index<n){
                int stone=0;
                while(index<n&&box[i][index] != '*'){
                    if(box[i][index] == '#')    stone++;
                    index++;
                }
                for(int j=index-stone; j<index; j++)   ans[j][m-i-1] = '#';
                if(index<n) ans[index][m-i-1] = '*';
                index++;
            }
        }
        return ans;
    }
};
