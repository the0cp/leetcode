class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int n:arr)  mp[n]++;
        unordered_set<int>set;
        for(auto n:mp)   set.insert(n.second);
        return set.size()==mp.size();
    }
};
