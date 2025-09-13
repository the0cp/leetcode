class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>freq;
        int con=0, vow=0;
        for(char c:s) freq[c]++;
        for(auto& [c, cnt]:freq){
            if(string("aeiou").find(c) != string::npos) vow=max(vow, cnt);
            else    con=max(con, cnt);
        }
        return con+vow;
    }
};
