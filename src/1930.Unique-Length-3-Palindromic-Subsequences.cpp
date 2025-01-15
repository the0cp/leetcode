class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>set;
        for(char e:s)   set.insert(e);
        int res=0;
        for(char e:set){
            int l=s.find_first_of(e);
            int r=s.find_last_of(e);
            if(l!=r){
                unordered_set<char>tmp;
                for(int i=l+1; i<r; i++)    tmp.insert(s[i]);
                res+=tmp.size();
            }
        }
        return res;
    }
};
