class Solution {
public:
    int num(char c){
        switch(c){
        case 'I': return 1;
        case 'X': return 10;
        case 'V': return 5;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int res=0;
        for(int i=0; i<s.length(); i++){
            if(i+1<s.length()){
                if(num(s[i+1])>num(s[i])){
                    res-=num(s[i]);
                    continue;
                }
            }
            res+=num(s[i]);
        }
        return res;
    }
};
