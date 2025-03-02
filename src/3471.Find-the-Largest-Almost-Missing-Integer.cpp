class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int n = nums.size();
        
        for(int i=0; i<=n-k; i++){
            unordered_set<int>window;
            for(int j=i; j<i+k; j++) window.insert(nums[j]);
            for(int n:window) freq[n]++;
        }
        int res=-1;
        for(auto& f : freq){
            if(f.second == 1) res=max(res, f.first);
        }
        
        return res;
    }
};
