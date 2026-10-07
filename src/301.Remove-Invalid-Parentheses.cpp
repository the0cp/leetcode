class Solution{
public:
    vector<string> ans;
    unordered_set<string> seen;

    void dfs(const string& s, int i, int bal, int l, int r, string& path){
        if(l+r > (int)s.size()-i)
            return;
        if(i==s.size()){
            if(bal==0 && l==0 && r==0 && seen.insert(path).second)
                ans.push_back(path);
            return;
        }

        char c=s[i];
        if(c=='('){
            if(l>0)dfs(s, i+1, bal, l-1, r, path);
            path.push_back(c);
            dfs(s, i+1, bal+1, l, r, path);
            path.pop_back();
        }else if(c==')'){
            if(r>0) dfs(s, i+1, bal, l, r-1, path);
            if(bal>0){
                path.push_back(c);
                dfs(s, i+1, bal-1, l, r, path);
                path.pop_back();
            }
        }else{
            path.push_back(c);
            dfs(s, i+1, bal, l, r, path);
            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s){
        int l=0,r=0;
        for(char c:s){
            if(c=='(')  l++;
            else if(c==')'){
                if(l>0) l--;
                else    r++;
            }
        }

        string path;
        dfs(s, 0, 0, l, r, path);
        return ans;
    }
};