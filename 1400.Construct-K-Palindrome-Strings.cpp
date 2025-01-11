class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k)    return false;
        sort(s.begin(),s.end());
        int odd=0;
        for(int i=0;i<s.length();){
            char current=s[i];
            int count=0;
            while(s[i]==current){
                count++;
                i++;
            }
            if(count%2!=0)  odd++;
        }
        return odd<=k;
    }
};
