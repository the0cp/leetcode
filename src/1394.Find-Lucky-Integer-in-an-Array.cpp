class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int n:arr)  freq[n]++;
        int lucky=-1;
        for(auto& [k,v]:freq){
            if(k==v)    lucky=max(lucky,k);
        }
        return lucky;
    }
};
