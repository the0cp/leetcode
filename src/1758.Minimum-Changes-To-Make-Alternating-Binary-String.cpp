class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int op[2]{};
        for(int i=0; i<n; i+=2){
            op[s[i]=='0']++;
            if(i+1<n)[[likely]] op[s[i+1]=='1']++;
        }
        return min(op[0], op[1]);
    }
};
