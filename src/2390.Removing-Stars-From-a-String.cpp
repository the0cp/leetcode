class Solution {
public:
    string removeStars(string s) {
        string res;
        for(char c:s){
            if(c=='*'&&!res.empty())    res.pop_back();
            else    res.push_back(c);
        }
        return res;
    }
};
