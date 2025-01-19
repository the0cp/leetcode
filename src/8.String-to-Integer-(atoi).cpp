class Solution {
public:
    int myAtoi(string s) {
        long long sign=1,flag=0,ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' ' && flag==0)
            continue;
            if(s[i]=='-' && flag==0){
                flag=1;
                sign=-1;
                continue;
            }
            if(s[i]=='+' && flag==0){
                flag=1;
                sign=1;
                continue;
            }
            int num=s[i]-'0';
            if(num>=0 && num<=9){
                flag=1;
                ans=ans*10+num;
                if(ans>INT_MAX && sign==-1) return INT_MIN;
                else if(ans>INT_MAX && sign==1) return INT_MAX;
            }else break;
        }
        return ans*sign;
    }
};