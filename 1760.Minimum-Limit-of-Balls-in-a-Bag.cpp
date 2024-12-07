class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1;
        int right=*max_element(nums.begin(), nums.end());
        int ans=0;
        while(left<=right){
            int m=(left+right)/2;
            long long op=0;
            for(int x:nums) op+=(x-1)/m; // op+=x/m; if(x%m==0) op--;
            if(op<=maxOperations){
                ans=m;
                right=m-1;
            }else{
                left=m+1;
            }
        }
        return ans;
    }
};
