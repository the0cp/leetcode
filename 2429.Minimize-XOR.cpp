class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int b = __builtin_popcount(num2), A = 0;
        for(int i = 31; i >= 0 && b; i--)
            if(num1 & (1 << i))    b--, A |= (1 << i);
        
        for(int i = 0; i <= 31 && b; i++)
            if((A & (1 << i)) == 0) b--, A |= (1 << i);
        return A;
    }
};
