class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(char c:s)   mp[c]++;
        int ans=0;
        for(auto e:mp)  ans+=(e.second-1)%2+1;
        return ans;
    }
};
