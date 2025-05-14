class Solution {
public:
    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>&g, unordered_set<string>&vis, double&ans, double val){
        if(vis.find(node)!=vis.end())   return;
        vis.insert(node);
        if(node==dest){
            ans=val;
            return;
        }
        for(auto&[b,v]:g[node]){
            dfs(b,dest,g,vis,ans,v*val);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>>g;
        for(int i=0; i<equations.size(); i++){
            string a=equations[i][0];
            string b=equations[i][1];
            double v=values[i];
            g[a][b]=v;
            g[b][a]=1.0/v;
        }
        vector<double>res;
        for(auto &q:queries){
            string a=q[0];
            string b=q[1];
            if(g.find(a)==g.end() || g.find(b)==g.end()){
                res.push_back(-1.0);
            }else{
                unordered_set<string>vis;
                double ans=-1.0;
                dfs(a,b,g,vis,ans,1.0);
                res.push_back(ans);
            }
        }
        return res;
    }
};
