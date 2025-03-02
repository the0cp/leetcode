class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        int len=n+m-1;
        string res(len,'.');
        vector<bool>flag(len,false);
        for(int i=0; i<n; i++){
            if(str1[i]=='T'){
                for(int j=i; j<i+m; j++){
                    if(res[j]=='.'){
                        res[j]=str2[j-i];
                        flag[j]=true;
                    }else if(res[j]!=str2[j-i]) return "";
                }
            }
        }
        for(int i=0; i<len; i++){
            if(res[i] == '.') res[i] = 'a';
        }
        for(int i=0; i<n; i++){
            if(str1[i]=='F'){
                bool match=true;
                vector<int>unfixed;
                for(int j=i; j<i+m; j++){
                    if(res[j]!=str2[j-i]){
                        match=false;
                        break;
                    }
                    if(!flag[j]) unfixed.push_back(j);
                }
                if(match){
                    if(unfixed.empty()) return "";
                    int j = unfixed.back();
                    bool changed = false;
                    for(char c=res[j]+1; c <= 'z'; c++){
                        if(c != str2[j - i]){
                            res[j] = c;
                            changed = true;
                            break;
                        }
                    }
                    if(!changed) return "";
                }
            }
        }
        return res;
    }
};
