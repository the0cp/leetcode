class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<long long> prev(n, 0), cur(n, 0);
        for(int t=1; t<=k; t++){
            long long bestLong=-prices[0];
            long long bestShort=prices[0];
            cur[0]=0;
            for(int i=1; i<n; i++){
                long long ans=cur[i-1];
                ans=max(ans, (long long)prices[i]+bestLong);
                ans=max(ans, -(long long)prices[i]+bestShort);
                cur[i]=ans;
                bestLong=max(bestLong, prev[i-1]-(long long)prices[i]);
                bestShort=max(bestShort, prev[i-1]+(long long)prices[i]);
            }
            prev.swap(cur);
        }
        return prev[n-1];
    }
};
