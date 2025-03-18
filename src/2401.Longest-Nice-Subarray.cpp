class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return 1;
        int ans=1;
        long long cur=nums[0];
        for(int i=0, j=1; i<n&&j<n;){
            while(i<j && (cur&nums[j])!=0){
                cur^=nums[i];   // xor clear
                i++;
            }
            cur|=nums[j];   // save nums[j]
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
