class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(), nums1.end());
        unordered_set<int>set2(nums2.begin(), nums2.end());
        vector<vector<int>>res(2, vector<int>(0));
        for(int n:set1){
            if(set2.count(n)==0)    res[0].push_back(n);
        }
        for(int n:set2){
            if(set1.count(n)==0)    res[1].push_back(n);
        }
        return res;
    }
};
