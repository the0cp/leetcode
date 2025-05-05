class Solution {
public:
    void backtracking(vector<vector<int>>&ans, vector<int>& cur, int cn, int k, int n){
        if(n<0||cur.size()>k) return;
        if(n==0 && cur.size()==k){
            ans.push_back(cur);
            return;
        }
        for(int i=cn; i<=9; i++){
            cur.push_back(i);
            backtracking(ans, cur, i+1, k, n-i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>cur;
        vector<vector<int>>ans;
        backtracking(ans, cur, 1, k, n);
        return ans;
    }
};
