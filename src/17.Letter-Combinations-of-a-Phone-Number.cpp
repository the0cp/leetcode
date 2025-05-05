class Solution {
private:
    vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void backtracking(int idx, const string&digits, string& cur, vector<string>&res){
        if(idx==digits.length()){
            res.push_back(cur);
            return;
        }
        string letters=mapping[digits[idx]-'0'];
        for(char l:letters){
            cur.push_back(l);
            backtracking(idx+1, digits, cur, res);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return {};
        vector<string>res;
        string cur;
        backtracking(0, digits, cur, res);
        return res;
    }
};
