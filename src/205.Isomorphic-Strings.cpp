class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>smp;
        unordered_map<char,int>tmp;
        for(int i=0; i<s.length(); i++){
            if(smp.find(s[i])==smp.end())   smp[s[i]]=i;
            if(tmp.find(t[i])==tmp.end())   tmp[t[i]]=i;
            if(smp[s[i]]!=tmp[t[i]])    return false;
        }
        return true;
    }
};
