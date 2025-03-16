class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries){
        int n = nums.size();
        unordered_map<int,vector<int>> pos;
        for(int i=0; i<n; i++)  pos[nums[i]].push_back(i);
        for(auto& p:pos)  sort(p.second.begin(), p.second.end());
        vector<int>ans;
        ans.reserve(queries.size());
        for(int q:queries){
            int val=nums[q];
            auto& list=pos[val];
            if(list.size()<=1){
                ans.push_back(-1);
                continue;
            }
            auto iter = lower_bound(list.begin(), list.end(), q);
            int pos = iter-list.begin();
            int lidx = (pos-1+list.size())%list.size();
            int ridx = (pos+1)%list.size();
            int ldis = min(abs(list[lidx]-q), n-abs(list[lidx] - q));
            int rdis = min(abs(list[ridx]-q), n-abs(list[ridx] - q));
            ans.push_back(min(ldis, rdis));
        }
        return ans;
    }
};
