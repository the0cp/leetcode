class Solution {
public:
    bool isPalindrome(int x) {
        string str1=to_string(x);
        string str2=str1;
        reverse(str1.begin(), str1.end());
        if(str1==str2)  return true;
        return false;
    }
};
