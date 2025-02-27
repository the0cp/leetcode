class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,unordered_map<int,int>>dp;
        int res=0;
        for(int i=0; i<arr.size(); i++) mp[arr[i]]=i;
        for(int j=1; j<arr.size(); j++){
            for(int i=0; i<j; i++){
                if(mp.find(arr[j]-arr[i])!=mp.end() && mp[arr[j]-arr[i]]<i){
                    dp[i][j]=dp[mp[arr[j]-arr[i]]][i]+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        res = res>0?res+=2:0;
        return res;
    }
};
