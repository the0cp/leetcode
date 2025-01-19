class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=1;
        for(int n:nums){
            if(n>0&&n==res) res++;
            else if(n>res)  return res;
        }
        return res;
    }
};