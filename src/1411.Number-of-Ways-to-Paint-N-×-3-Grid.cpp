class Solution {
public:
    int numOfWays(int n) {
        const int mod=1e9+7;
        long long x=6, y=6;
        for(int i=2; i<=n; i++){
            long long newx=(3*x+2*y)%mod;
            long long newy=(2*x+2*y)%mod;
            x=newx;
            y=newy;
        }
        return (x+y)%mod;
    }
};
