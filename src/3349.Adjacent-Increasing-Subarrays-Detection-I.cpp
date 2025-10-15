class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev=0, cnt=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]) cnt++;
            else{
                prev=cnt;
                cnt=1;
            }
            if(cnt/2>=k || prev/2>=k || min(cnt, prev)>= k)
                return true;
        }
        return false;
    }
};
