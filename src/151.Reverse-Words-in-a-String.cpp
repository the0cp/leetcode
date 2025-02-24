class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res;
        vector<string>words;
        while(ss>>word) words.push_back(word);
        reverse(words.begin(), words.end());
        for(string w:words) res += w+" ";
        res.erase(res.size()-1);
        return res;
    }
};
