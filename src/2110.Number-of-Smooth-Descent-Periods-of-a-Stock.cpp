class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const int n=prices.size();
        long long dp=1, ans=1;
        for(int i=1; i<n; i++){
            dp=(prices[i]+1==prices[i-1])*dp+1;
            ans+=dp;
        }
        return ans;
    }
};
