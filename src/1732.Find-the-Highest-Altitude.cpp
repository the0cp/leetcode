class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt=0;
        int curAlt=0;
        for(int i=0; i<gain.size(); i++){
            curAlt+=gain[i];
            maxAlt=max(maxAlt, curAlt);
        }
        return maxAlt;
    }
};
