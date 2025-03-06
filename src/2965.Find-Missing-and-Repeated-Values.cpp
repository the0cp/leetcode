class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int repeat=0, miss=0, sum=0;
        for(auto row:grid){
            for(int i:row){
                mp[i]++;
                sum++;
            }
        }
        for(int i=1; i<=sum; i++){
            if(mp[i]==2)    repeat=i;
            else if(mp[i]==0)   miss=i;
        }
        return {repeat,miss};
    }
};
