class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int>root(m+1);
        iota(root.begin(), root.end(), 0);
        auto find = [&root](int n) -> int {
            while(root[n] != n)    n = root[n];
            return n;
        };
        for(int i=0; i<m; i++){
            int ra=find(edges[i][0]);
            int rb=find(edges[i][1]);
            if(ra==rb)   return edges[i];
            else    root[ra]=rb;
        }
        return {};
    };
};
