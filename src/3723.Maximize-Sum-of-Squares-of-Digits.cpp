class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)   return "";
        string s(num, '0');
        auto [q, r] = div(sum, 9);
        fill(s.begin(), s.begin()+q, '9');
        s[q]='0'+r;
        return s;
    }
};