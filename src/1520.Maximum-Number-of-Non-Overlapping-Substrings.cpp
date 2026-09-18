class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<pair<int, int>>range(26, {n, -1});
        vector<pair<int, int>> intervals;
        for(int i=0; i<n; i++){
            int c=s[i]-'a';
            range[c].first=min(range[c].first, i);
            range[c].second=i;
        }
        for(int c=0; c<26; c++){
            if(range[c].second==-1) continue;
            auto [l, r] = range[c]; 
            bool valid = true;
            for(int i=l; i<=r; i++){
                int j=s[i]-'a';
                if(range[j].first<l){
                    valid=false;
                    break;
                }
                r=max(r, range[j].second);
            }
            if(valid)   intervals.push_back({r, l});
        }

        ranges::sort(intervals);

        vector<string> ans;
        int prevEnd = -1;

        for(auto [r, l] : intervals){
            if(l > prevEnd){
                ans.push_back(s.substr(l, r-l+1));
                prevEnd = r;
            }
        }

        return ans;
    }
};
