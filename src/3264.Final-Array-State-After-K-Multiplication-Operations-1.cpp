class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>q;
        for(int i=0; i<nums.size(); i++)    q.push({nums[i], i});
        while(k-->0){
            auto p=q.top();
            int i=p.second;
            q.pop();
            nums[i]*=multiplier;
            q.push({nums[i], i});
        }
        return nums;
    }
};
