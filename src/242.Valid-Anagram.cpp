class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())  return false;
        unordered_map<char,int>cnt;
        for(char c:s)   cnt[c]++;
        for(char c:t){
            if(cnt.find(c)==cnt.end() || cnt[c]==0) return false;
            cnt[c]--;
        }
        return true;
    }
};
