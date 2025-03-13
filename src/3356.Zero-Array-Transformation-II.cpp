class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        int sum_d = 0, k = 0;
        for(int i=0; i<n; i++){
            int x=nums[i];
            sum_d+=diff[i];
            while(k<queries.size() && sum_d<x){
                auto &q=queries[k];
                int l=q[0], r=q[1], val=q[2];
                diff[l]+=val;
                diff[r+1]-=val;
                if(l<=i && i<=r) sum_d+=val;
                k++;
            }
            if(sum_d < x)  return -1;
        }
        return k;
    }
};
