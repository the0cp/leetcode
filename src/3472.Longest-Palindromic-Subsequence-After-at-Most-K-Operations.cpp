class Solution {
public:
    int cost(char a, char b){
        int diff=abs(a-b);
        return min(diff, 26-diff);
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        std::vector<std::vector<std::vector<int>>>dp(n, std::vector<std::vector<int>>(n, std::vector<int>(k + 1, 0)));
        for(int i=0; i<n; i++)
            for(int j=0; j<=k; j++)
                dp[i][i][j]=1;
        for(int len=2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j=i+len-1;
                for(int h=0; h<=k; h++){
                    if(s[i] == s[j]){
                        dp[i][j][h] = 2 + dp[i + 1][j - 1][h];
                    }else{
                        int case1=dp[i+1][j][h];
                        int case2=dp[i][j-1][h];
                        int c = cost(s[i], s[j]);
                        int case3 = (h>=c) ? 2+dp[i+1][j-1][h-c] : 0;
                        dp[i][j][h] = max({case1, case2, case3});
                    }
                }
            }
        }
        return dp[0][n-1][k];
    }
};
