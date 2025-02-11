class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int len1=s.size();
        int len2=part.size();
        for(int i=0; i<len1; i++){
            res.push_back(s[i]);
            while(res.size()>=len2 && res.back()==part.back() && res.substr(res.size()-len2, len2)==part){
                for(int j=0; j<len2; j++)   res.pop_back();
            }
        }
        return res;
    }
};
