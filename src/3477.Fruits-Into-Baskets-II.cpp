class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>used(baskets.size(),false);
        int ans=0;
        for(int f:fruits){
            bool placed=false;
            for(int i=0; i<baskets.size(); i++){
                if(!used[i]&&baskets[i]>=f){
                    used[i]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed) ans++;
        }
        return ans;
    }
};
