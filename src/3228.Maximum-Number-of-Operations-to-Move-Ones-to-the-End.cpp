class Solution {
public:
    int maxOperations(string s) {
        int cnt=0;
        int n=s.size();
        int cnt1=(s[0]=='1');
        for(int i=1; i<n; i++){
            cnt+=(-(s[i]=='0'&&s[i-1]=='1'))&(cnt1+=s[i]=='1');
        }
        return cnt;
    }
};
