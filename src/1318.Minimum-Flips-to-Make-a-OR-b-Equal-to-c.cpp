class Solution {
public:
    int minFlips(int a, int b, int c) {
        return popcount<uint>(c^=(a|b)) + popcount<uint>(a&b&c);
    }
};
