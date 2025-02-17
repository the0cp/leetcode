class Solution {
public:
    int backtracking(vector<int>&count){
        int ans=0;
        for(int &c:count){
            if(c==0)    continue;
            c--;
            ans+=1+backtracking(count);
            c++;
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>count(26,0);
        for(auto c:tiles)   count[c-'A']++;
        return backtracking(count);
    }
};
