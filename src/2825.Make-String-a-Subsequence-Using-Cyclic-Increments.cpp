class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        if(m<n) return false;
        auto increment=[](char c){return (c+1-'a')%26 + 'a';};
        int j=0;
        for(int i=0; i<m&&j<n; i++){
            if(str1[i]==str2[j] || increment(str1[i])==str2[j]) j++;
        }
        return j==n;
    }
};
