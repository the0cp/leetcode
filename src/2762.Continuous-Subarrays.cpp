class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        multiset<int>s;
        for(int l=0, r=0; r<nums.size(); r++){
            s.insert(nums[r]);
            while(*s.rbegin()-*s.begin() > 2)   s.erase(s.find(nums[l++]));
            ans+=r-l+1;
        }
        return ans;
    }
};
