class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>mp(nums.begin(), nums.end());
        while(mp.find(original)!=mp.end()) original=original*2;
        return original;
    }
};
