class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int>tick;
        vector<int>dp(366, INT_MAX);
        dp[0]=0;
        tick[1]=costs[0];
        tick[7]=costs[1];
        tick[30]=costs[2];
        for(int i=1; i<=365; i++){
            if(find(days.begin(), days.end(), i)==days.end()){
                dp[i]=dp[i-1];
                continue;
            }
            for(auto t:tick){
                dp[i]=min(dp[max(0,i-t.first)]+t.second, dp[i]);
            }
        }
        return dp[365];
    }
};
