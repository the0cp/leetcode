class Solution {
public:
    static bool compare(const pair<char, int>& a, const pair<char, int>& b) {
        return a.first > b.first;
    }
    string repeatLimitedString(string s, int k) {
        string ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;

        vector<pair<char, int>>vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), compare);
        int slow=0;
        int fast=1;
        int n=vec.size();
        while(fast<n){
            if(vec[slow].second<=k){
                for(int i=0;i<vec[slow].second;i++) ans.push_back(vec[slow].first);
                vec[slow].second=0;
                slow++;
                if(fast==slow)  fast++;
            }else{
                for(int i=0;i<k;i++)    ans.push_back(vec[slow].first);
                vec[slow].second-=k;
                if(vec[fast].second>0){
                    ans.push_back(vec[fast].first);
                    vec[fast].second--;
                }
                if(vec[fast].second==0) fast++;
            }
        }
        if(vec[slow].second!=0){
            for(int i=0;i<min(vec[slow].second,k);i++){
                ans.push_back(vec[slow].first);
            }
        }
        return ans;
    }
};
