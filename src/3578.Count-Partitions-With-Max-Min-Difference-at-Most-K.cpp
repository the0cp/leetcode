class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod=1e9+7;
        int n=(int) nums.size();
        vector<int>dp(n+1, 0);
        vector<int>psum(n+1, 0);
        dp[0]=1;
        psum[0]=1;

        deque<int>maxq, minq;
        int l=0;

        for(int r=0; r<n; r++){
            while(!maxq.empty()&&nums[maxq.back()]<=nums[r])    maxq.pop_back();
            maxq.push_back(r);
            while(!minq.empty()&&nums[minq.back()]>=nums[r])    minq.pop_back();
            minq.push_back(r);
            while(nums[maxq.front()]-nums[minq.front()]>k){
                if(maxq.front()==l) maxq.pop_front();
                if(minq.front()==l) minq.pop_front();
                l++;
            }
            long long cur=psum[r];
            if(l>0) cur=(cur+(mod-psum[l-1]))%mod;
            dp[r+1]=cur;
            psum[r+1]=(psum[r]+dp[r+1])%mod;
        }
        return dp[n];
    }
};
