class Solution {
    unordered_map<string, vector<char>>mp;
public:
    bool dfs(string bot, int i, string tmp){
        if(bot.size()==1)   return true;
        if(i==bot.size()-1){
            string nextRow;
            return dfs(tmp, 0, nextRow);
        }
        string key = bot.substr(i, 2);
        for(char v:mp[key]){
            tmp.push_back(v);
            if(dfs(bot, i+1, tmp))  return true;
            tmp.pop_back();
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto& a:allowed){
            mp[a.substr(0, 2)].push_back(a[2]);
        }
        string tmp;
        return dfs(bottom, 0, tmp);
    }
};
