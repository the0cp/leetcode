class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<unordered_set<int>>valid(n);
        for(int i=0; i<n; i++) valid[i].insert(0);
        bool null = true;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                null=false;
                break;
            }
        }
        if(null) return 0;
        for(int i=0; i < queries.size(); ++i){
            int left=queries[i][0];
            int right=queries[i][1];
            int dec=queries[i][2];
            for(int j=left; j<=right; j++){
                unordered_set<int> updated;
                for(int v:valid[j]){
                    updated.insert(v);
                    updated.insert(v + dec);
                }
                valid[j] = updated;
            }
            bool allReached = true;
            for(int i=0; i<n; i++){
                if(valid[i].count(nums[i]) == 0){
                    allReached = false;
                    break;
                }
            }
            if(allReached) return i + 1;
        }
        return -1;
    }
};
