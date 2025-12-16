class Solution {
public:
    vector<vector<int>> tree;
    vector<int> buyPrice, sellPrice;
    int gbudget;

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        buyPrice=present;
        sellPrice=future;
        gbudget=budget;

        tree.assign(n, {});
        for(auto &h:hierarchy){
            tree[h[0]-1].push_back(h[1]-1);
        }

        auto dp = dfs(0);
        return dp[gbudget][0];
    }

    vector<vector<int>>dfs(int u){
        vector<vector<int>>dp(gbudget+1, vector<int>(2,0));
        for(int v:tree[u]){
            auto child=dfs(v);
            vector<vector<int>>next(gbudget+1, vector<int>(2,0));
            for(int b=0; b<=gbudget; b++){
                for(int cb=0; cb<=b; cb++){
                    next[b][0]=max(next[b][0], dp[b-cb][0]+child[cb][0]);
                    next[b][1]=max(next[b][1], dp[b-cb][1]+child[cb][1]);
                }
            }
            dp.swap(next);
        }
        vector<vector<int>>ans(gbudget+1, vector<int>(2,0));
        int disc=buyPrice[u]/2;
        for(int b=0; b<=gbudget; b++){
            ans[b][0] = dp[b][0];
            if (b >= buyPrice[u])
                ans[b][0]=max(ans[b][0], sellPrice[u]-buyPrice[u]+dp[b-buyPrice[u]][1]);

            ans[b][1] = dp[b][0];
            if (b >= disc)
                ans[b][1]=max(ans[b][1], sellPrice[u]-disc+dp[b-disc][1]);
        }
        return ans;
    }
};
