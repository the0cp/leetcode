class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>diff(s.size()+1);
        for(auto&e:shifts){
            int add=(e[2]==1 ? 1 : -1);
            diff[e[0]]+=add;
            diff[e[1]+1]-=add;
        }
        for(int i=0, d=0; i<s.size(); i++){
            d+=diff[i];
            s[i] = ((s[i]+d-'a') % 26 + 26) % 26 + 'a';
        }
        return s;
    }
};
