class Solution {
public:
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        if(n==4)return 4;
        int result=1;
        while(n>4){
            result*=3;
            n-=3;
        }
        result*=n;
        return result;
    }
};


/*
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        //dp[0]=dp[1]=0;
        dp[2]=1;
        for(int i=3; i<=n; i++){
            for(int j=1; j<=i/2; j++){
                dp[i]=max(j*(i-j), max(j*dp[i-j], dp[i]));
            }
        }
        return dp[n];
    }
};
*/
