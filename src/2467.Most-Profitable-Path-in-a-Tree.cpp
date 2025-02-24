class Solution {
private:
    map<int,vector<int>>G;
    unordered_map<int,int>timea;
    unordered_map<int,int>timeb;
    vector<int>pathb;
    vector<int>amt;
    bool is_bfind;
    int ans=INT_MIN;
public:
    void dfs(int cur, int pre, int amount){
        if(G[cur].size()==1 && G[cur][0]==pre){
            ans=max(ans,amount);
            return;
        }
        for(auto next:G[cur]){
            if(next==pre)  continue;
            if(timeb.find(next)==timeb.end() || timea[next]<timeb[next]) dfs(next, cur, amount+amt[next]);  
            // alice is faster or a bob untraveled node
            else if(timea[next]==timeb[next])   dfs(next, cur, amount+amt[next]/2);
            // arrive at the same time
            else dfs(next, cur, amount);
            // bob is faster
        }
    }

    void dfsa(int cur, int pre, int t){
        timea[cur]=t;
        for(auto &next:G[cur])  if(next!=pre)   dfsa(next, cur, t+1);
    }
    
    void dfsb(int cur, int next){
        if(is_bfind)    return;
        pathb.push_back(cur);
        if(cur==0){
            is_bfind=true;
            for(int i=0; i<pathb.size(); i++) timeb[pathb[i]] = i;
            return;
        }
        for(auto pre:G[cur]){
            if(pre!=next)   dfsb(pre, cur);
            if(is_bfind)    return;
        }
        pathb.pop_back();
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        amt=amount;
        for(auto &e:edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        dfsb(bob,-1);
        dfsa(0,-1,0);
        dfs(0,-1,amt[0]);
        return ans;
    }
};
