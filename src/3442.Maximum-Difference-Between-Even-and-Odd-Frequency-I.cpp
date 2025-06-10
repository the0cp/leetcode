class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int>freq;
        for(char c:s)   freq[c]++;
        int maxOdd=INT_MIN;
        int minEven=INT_MAX;
        for(auto &pair:freq){
            if(pair.second%2==0){
                minEven=min(minEven, pair.second);
            }else{
                maxOdd=max(maxOdd, pair.second);
            }
        }
        return maxOdd-minEven;
    }
};
