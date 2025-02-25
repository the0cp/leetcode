class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>vowel={'a','e','i','o','u'};
        int len=0, maxLen=0;
        for(int i=0; i<k; i++)  if(vowel.count(s[i]))   len++;
        maxLen=len;
        for(int left=0,right=k; right<s.length(); left++,right++){
            if(vowel.count(s[left]))    len--;
            if(vowel.count(s[right]))   len++;
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};
