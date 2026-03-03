class Solution {
public:
    char findKthBit(int n, int k) {
        return k==1?'0':((k&(k-1))==0?'1':'0'+1-(findKthBit(n, (1<<(bit_width((unsigned)k)))-k)-'0'));
    }
};
