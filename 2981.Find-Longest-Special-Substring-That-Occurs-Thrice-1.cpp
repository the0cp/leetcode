class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>>freq;
        int n=s.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt++;
            if(i==n-1 || s[i]!=s[i+1]){
                freq[s[i]].push_back(cnt);
                cnt=0;
            }
        }

        int ans=0;
        for(auto& [_,v]:freq){
            sort(v.begin(), v.end(), greater<int>());
            v.resize(3);
            int maxlen=max({v[0]-2, min(v[0]-1, v[1]), v[2]});
            ans=max(ans, maxlen);
        }
        return ans==0 ? -1 : ans;
    }
};
