class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int n:nums) mp[n]++;
        for(const auto& [_, c]:mp) {
            if(c%2!=0) return false;
        }
        return true;
    }
};
