class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for(int i=0; i < words.size(); ++i)
            for(int j=i+1; j < words.size(); ++j) 
                if(isPrefixAndSuffix(words[i], words[j])) res++;
        return res;
    }

    bool isPrefixAndSuffix(const string& a, const string& b) {
        if(b.size() < a.size()) return false;
        int len = a.size();
        if(b.substr(0, len)==a && b.substr(b.size()-len, len)==a) return true;
        else return false;
    }   
};
