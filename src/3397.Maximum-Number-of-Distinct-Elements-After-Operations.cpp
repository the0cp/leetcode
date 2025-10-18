class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int cnt=0;
        int prev=INT_MIN;
        for(int a:nums){
            int low=a-k;
            int high=a+k;
            int x=prev+1;
            if(x<low)   x=low;
            if(!(x>high)){
                cnt++;
                prev=x;
            }
        }
        return cnt;
    }
};
