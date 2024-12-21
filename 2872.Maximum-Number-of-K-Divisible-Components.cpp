class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>g(n);
        for(auto& e: edges){
            int x=e[0], y=e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans=0;
        function<long long(int, int)> dfs = [&](int x, int yy) -> long long {
            long long sum=values[x];
            for (int y : g[x])
                if (y!=yy)    sum+=dfs(y, x);
            ans += sum%k==0;
            return sum;
        };
        dfs(0,-1);
        return ans;
    }
};
