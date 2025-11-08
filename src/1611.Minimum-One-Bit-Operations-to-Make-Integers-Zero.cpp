class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)    return 0;
        int k=31-__builtin_clz(n);
        int op=(1<<(k+1))-1;
        return op-minimumOneBitOperations(n^(1<<k));
    }
};
