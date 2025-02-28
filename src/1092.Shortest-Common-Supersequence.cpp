class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<string> prev(n2+1), curr(n2+1);
        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){
                if(str1[i-1]!=str2[j-1]){
                    curr[j] = prev[j].size()>curr[j-1].size() ? prev[j] : curr[j-1];
                }else curr[j] = prev[j-1] + str1[i-1];
            }
            prev = curr;
        }
        string res = "";
        const string& lcs = curr[n2];
        int i=0, j=0;
        for(char c : lcs){
            while(i<n1 && str1[i]!=c){
                res += str1[i];
                i++;
            }
            while(j<n2 && str2[j]!=c){
                res += str2[j];
                j++;
            }
            res += c;
            i++;
            j++;
        }
        return res + str1.substr(i) + str2.substr(j);
    }
};
