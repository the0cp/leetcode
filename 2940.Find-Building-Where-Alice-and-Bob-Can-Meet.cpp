class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& _h, vector<vector<int>>& q) {
        int n=_h.size();
        int m=q.size();
        vector<int> ans(m);
        map<pair<int,int>,int> mp;
        for (int i=0;i<m;++i){
            int res=-1;
            int mi=min(q[i][0],q[i][1]);
            int ma=max(q[i][0],q[i][1]);
            auto pr=make_pair(mi,ma);
            if (mp.find(pr)!=mp.end())  res=mp[pr];
            else if(ma==mi||_h[ma]>_h[mi]){
                res=ma;
            }else{
                for(int j=ma+1;j<n;++j)
                    if(_h[j]>_h[mi]){
                        res=j;
                        break;
                    }
            }
            mp[pr]=ans[i]=res;
        }
        return ans;
    }
};
