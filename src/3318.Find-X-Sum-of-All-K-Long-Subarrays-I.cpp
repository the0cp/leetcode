class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0; i<=n-k; i++){
            vector<int>sub(nums.begin()+i, nums.begin()+i+k);
            unordered_map<int,int>freq;
            for(int n:sub)  freq[n]++;
            vector<pair<int,int>>items(freq.begin(), freq.end());
            sort(items.begin(), items.end(), [](auto &a, auto &b){
                if(a.second==b.second)  return a.first>b.first;
                return a.second>b.second;
            });
            int sum=0;
            for(int j=0; j<items.size()&&j<x; j++){
                sum+=items[j].first*items[j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
