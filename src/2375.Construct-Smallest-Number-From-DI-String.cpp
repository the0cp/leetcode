class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size()+1;
        string a;
        for(int i=1; i<=n; i++)  a+=(char)(i+'0');
        int p=0;
        while(p<n-1){
            if(pattern[p]=='I') p++;
            else{
                int cnt=0;
                int st=p;
                while(p<n-1 && pattern[p]=='D')  p++, cnt++;
                reverse(a.begin()+st, a.begin()+st+cnt+1);
            }
        }
        return a;
    }
};
