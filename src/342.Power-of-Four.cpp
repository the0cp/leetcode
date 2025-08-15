class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n-1)%3==0 && n==(n&-n);
    }
};
