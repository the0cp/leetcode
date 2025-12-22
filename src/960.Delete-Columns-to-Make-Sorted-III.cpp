class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if(strs.empty()) return 0;
        int m=strs[0].size();
        vector<vector<int>> adj(m);
        vector<int> deg(m,0);
        for(int j=0;j<m-1;++j){
            for(int last=j+1;last<m;++last){
                if(all_of(strs.begin(),strs.end(),[&](const string& s){return s[j]<=s[last];})){
                    adj[j].push_back(last);
                    deg[last]++;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<m;++i){
            if(deg[i]==0) q.push(i);
        }
        int d=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front();
                q.pop();
                for(int v:adj[u]){
                    if(--deg[v]==0) q.push(v);
                }
            }
            d++;
        }
        return m-d;
    }
};
