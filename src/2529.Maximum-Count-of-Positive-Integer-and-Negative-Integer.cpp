class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0, neg=0;
        for(int n:nums){
            pos+=n>0;
            neg+=n<0;
        }
        return max(pos, neg);
    }
};
