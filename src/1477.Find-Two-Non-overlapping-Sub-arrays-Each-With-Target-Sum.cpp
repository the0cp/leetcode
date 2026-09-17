class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0, i=0, j=0;
        vector<int>dp(n, INT_MAX);
        int minLen=INT_MAX;
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            while(sum>target)   sum-=arr[j++];
            if(sum==target){
                int len=i-j+1;
                if(j>0 && dp[j-1]!=INT_MAX) ans=min(ans, dp[j-1]+len);
                minLen=min(minLen, len);
            }
            dp[i]=minLen;
        }

        return ans==INT_MAX?-1:ans;
    }
};
