class Solution {
public:
    int distinctSubseqII(string s) {
        const long long mod = 1e9+7;
        long long dp = 1;
        vector<long long>last(26, 0);
        
        for(char c:s){
            int index = c - 'a';
            long long old = dp;
            dp = (2 * dp - last[index] + mod) % mod;
            last[index] = old;
        }

        return (dp - 1 + mod) % mod;
    }
};
