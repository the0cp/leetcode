class Solution {
public:
    int find(vector<vector<int>>& edges) {
        vector<vector<int>>g(edges.size() + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int res=0;
        auto dfs = [&](auto&& dfs, int x, int fa) -> int {
            int max_len=0;
            for (auto y : g[x]) {
                if (y != fa) {
                    int sub_len = dfs(dfs, y, x) + 1;
                    res = max(res, max_len + sub_len);
                    max_len = max(max_len, sub_len);
                }
            }
            return max_len;
        };
        dfs(dfs, 0, -1);
        return res;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = find(edges1);
        int d2 = find(edges2);
        return max({d1, d2, (d1+1)/2+(d2+1)/2 + 1});
    }
};
