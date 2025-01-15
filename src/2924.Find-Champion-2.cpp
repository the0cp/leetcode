class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>vec(n);
        for(vector<int>& edge : edges){
            vec[edge[1]]++;
        }
        int cnt = 0;
        int winner;
        for(int i=0; i<n; i++){
            if(!vec[i]){
                cnt++;
                winner = i;
            }
        }
        return cnt==1?winner:-1;
    }
};
