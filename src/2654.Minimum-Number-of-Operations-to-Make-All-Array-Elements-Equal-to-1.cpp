class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int res=INT_MAX;
        for(int n:nums) cnt1+=(n==1);
        if(cnt1)    return n-cnt1;
        for(int i=0; i<n; i++){
            int a=nums[i];
            for(int j=i+1; j<n; j++){
                a=gcd(a, nums[j]);
                if(a==1){
                    res=min(res, j-i+n-1);
                    break;
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};
