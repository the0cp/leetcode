class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>set;
        int res=0, left=0, cur=0;
        for(int right=0; right<nums.size(); right++){
            while(set.find(nums[right])!=set.end()){
                cur-=nums[left];
                set.erase(nums[left]);
                left++;
            }
            cur+=nums[right];
            set.insert(nums[right]);
            res=max(res, cur);
        }
        return res;
    }
};
