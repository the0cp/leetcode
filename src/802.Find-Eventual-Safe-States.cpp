class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_set<int>se;
        for(int i=0; i<graph.size(); i++)
            if(graph[i].size()==0) se.insert(i);
        while(true){
            int x = se.size();
            for(int i=0;i<graph.size();i++){
                bool ins = true;
                for(auto el:graph[i]){
                    if(se.find(el)==se.end()){
                        ins = false;
                        break;
                    }
                }
                if(ins) se.insert(i);
            }
            if(se.size()==x) break;
        }
        vector<int>ans(se.begin(), se.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};