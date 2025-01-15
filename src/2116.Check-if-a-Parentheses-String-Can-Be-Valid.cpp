class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        int flag=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(locked[i]=='0'){
                s[i]=')';
                cnt++;
            }
            if(s[i]=='(')   flag++;
            else    flag--;
            if(flag<0){
                if(cnt==0)  return false;
                cnt--;
                flag+=2;
            }
        }
        return flag==0;
    }
};
