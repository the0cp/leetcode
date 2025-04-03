class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m=potions.size();
        vector<int>ans;
        for(int s:spells){
            long long low = (success+s-1)/s;
            int cnt=lower_bound(potions.begin(), potions.end(), low) - potions.begin();
            ans.push_back(m-cnt);
        }
        return ans;
    }
};
