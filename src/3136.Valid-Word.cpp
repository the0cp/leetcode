class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;
        int vow=0, con=0;
        string list="aeiouAEIOU";
        
        for(char c:word){
            if(isalpha(c)){
                if(list.find(c)!=string::npos)  vow++;
                else    con++;
            }else if(!isdigit(c)){
                return false;
            }
        }
        return vow>0 && con>0;
    }
};
