class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        function<void(int)> dfs = [&](int cur){
            if(cur>n) return;
            res.push_back(cur);
            for(int i=0; i<=9; i++){
                int next=cur*10+i;
                if(next>n) break;
                dfs(next);
            }
        };

        for(int i=1; i<=9; i++) dfs(i);
        return res;
    }
};
