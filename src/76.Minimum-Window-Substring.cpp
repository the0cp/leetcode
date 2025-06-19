class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(n>m) return "";
        unordered_map<char,int>tfreq;
        unordered_map<char,int>sfreq;
        for(char c:t){
            tfreq[c]++;
        }
        int left=0, right=0, cnt=0;
        int st=0, minLen=INT_MAX;
        for(; right<m; right++){
            char rc=s[right];
            sfreq[rc]++;
            if(tfreq.find(rc)!=tfreq.end()&&sfreq[rc]<=tfreq[rc])  cnt++;
            if(cnt==n){
                char lc=s[left];
                while(tfreq[lc]==0||sfreq[lc]>tfreq[lc]){
                    sfreq[lc]--;
                    left++;
                    lc=s[left];
                }
                if(minLen>right-left+1){
                    minLen=right-left+1;
                    st=left;
                }
            }
        }
        if(minLen==INT_MAX) return "";
        return s.substr(st, minLen);
    }
};
