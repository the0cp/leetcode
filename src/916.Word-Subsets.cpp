class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>w1m;
        unordered_map<char,int>w2m;
        for(int i=0; i<words2.size();i++){
            unordered_map<char,int>tmp;
            tmp.clear();
            for(char c:words2[i])   tmp[c]++;
            for(auto [c,n]:tmp){
                auto it=w2m.find(c);
                if(it==w2m.end())   w2m[c]=n;
                else    w2m[c]=max(n,it->second);
            }
        }
        vector<string>res;
        for(string &word:words1){
            bool flag=true;
            w1m.clear();
            for(char c:word)    w1m[c]++;
            for(auto [c,n]:w2m){
                auto it=w1m.find(c);
                if(it==w1m.end()){
                    flag=false;
                    break;
                }else{
                    if(n>it->second){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)    res.emplace_back(word);
        }
        return res;
    }
};
