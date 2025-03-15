class Solution {
public:
    bool check(vector<int>&nums, int mid, int k){
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }

    int minCapability(vector<int>& nums, int k) {
        int high=*max_element(nums.begin(), nums.end());
        int ans=high;
        int low=1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(check(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
