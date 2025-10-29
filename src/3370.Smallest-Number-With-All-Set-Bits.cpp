class Solution {
public:
    int smallestNumber(int n) {
        return bit_ceil((unsigned)n+1)-1;   
    }
};
