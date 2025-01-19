class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<bool>ans(m);
        vector<int>s(n);
        for(int i=1; i<n; i++)  s[i]=s[i-1]+(nums[i]%2==nums[i-1]%2);
        for(int i=0; i<m; i++){
            auto& pair=queries[i];
            ans[i]= s[pair[0]]==s[pair[1]];
        }
        return ans;
    }
};
