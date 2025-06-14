class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res=0;
        int maj=0;
        for(int n:nums){
            mp[n]++;
            if(mp[n]>maj){
                res=n;
                maj=mp[n];
            }
        }
        return res;
    }
};
