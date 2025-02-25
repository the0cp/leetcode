class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum;
        double window=0;
        for(int i=0; i<k; i++)  window+=nums[i];
        sum=window;
        for(int i=0,j=k; j<nums.size(); i++,j++){
            window+=nums[j];
            window-=nums[i];
            sum=max(sum,window);
        }
        return sum/k;
    }
};
