class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n+1);
        for(auto edge:edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        unordered_map<int,int>mp;
        for(int i=1; i<=n; i++){
            queue<int>q;
            q.push(i);
            vector<int>dis(n+1);
            dis[i]=1;
            int idx=n;
            int maxLength=1;
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                idx=min(cur,idx);
                for(auto e:g[cur]){
                    if(dis[e]==0){
                        dis[e]=dis[cur]+1;
                        maxLength=max(maxLength,dis[e]);
                        q.push(e);
                    }
                    if(abs(dis[e]-dis[cur]) != 1)   return -1;
                }
            }
            mp[idx]=max(mp[idx], maxLength);
        }
        int ans=0;
        for(auto&g:mp)  ans+=g.second;
        return ans;
    }
};