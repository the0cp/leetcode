class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,int>color;
        unordered_map<int,int>cnt;
        for(const auto&q:queries){
            int x=q[0];
            int y=q[1];
            auto it=color.find(x);
            if(it!=color.end())
                if(--cnt[it->second]==0)    
                    cnt.erase(it->second);
            color[x]=y;
            cnt[y]++;
            ans.push_back(cnt.size());
        }
        return ans;
    }
};