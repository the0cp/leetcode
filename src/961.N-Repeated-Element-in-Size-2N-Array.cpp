class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>set;
        for(int x:nums){
            if(!set.insert(x).second)   return x;
        }
        return -1;
    }
};
