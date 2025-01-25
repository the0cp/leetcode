class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
        int n = nums.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j){return nums[i] < nums[j];});
        vector<int> ans(n);
        int i=0;
        while(i<n){
            int st=i++;
            while(i<n && nums[ids[i]]-nums[ids[i-1]] <= limit)  i++; // find sub seg
            vector<int>subIds(ids.begin()+st, ids.begin()+i);
            sort(subIds.begin(), subIds.end());
            for(int j=0; j<subIds.size(); j++)
                ans[subIds[j]] = nums[ids[st+j]];
        }
        return ans;
    }
};