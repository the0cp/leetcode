class Solution {
public:
    void generate(string s, vector<string>&list, int n){
        if(s.size()==n){
            list.push_back(s);
            return;
        }
        for(char c:{'a','b','c'}){
            if(!s.empty() && s.back()==c) continue;
            generate(s+c, list, n);
        }
    }
    string getHappyString(int n, int k) {
        if(k>3*pow(2, n-1)) return "";
        vector<string>list;
        generate("", list, n);
        return list[k-1];
    }
};
