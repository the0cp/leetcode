class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int>freq;
        unordered_map<int,int>range;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i:nums){
            freq[i]++;
            maxi=max(i+k, maxi);
            mini=min(i-k, mini);
            range[i+k+1]--;
            range[i-k]++;
        }
        int cnt=1;
        for(int i=mini; i<=maxi; i++){
            range[i]+=range[i-1];
            int val=freq[i];
            int left=range[i]-val;
            int op=min(left, numOperations);
            cnt=max(cnt,op+val);
        }
        return cnt;
    }
};
