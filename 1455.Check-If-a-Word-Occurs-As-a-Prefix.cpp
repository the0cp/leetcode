class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s=" "+sentence;
        string w=" "+searchWord;
        int m=s.size();
        int idx=s.find(w);
        if(idx==-1)   return -1;
        return count(s.begin(), s.begin()+idx+1, ' ');
    }
};
