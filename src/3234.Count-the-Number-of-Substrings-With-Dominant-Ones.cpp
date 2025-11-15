class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        deque<int>zero;
        int zmax=(sqrt(1.0+4*n)-1)/2;
        for(int i=0; i<n; i++)  if(s[i]=='0')   zero.push_back(i);
        zero.push_back(n);
        int ans=0;
        for(int l=0; l<n; l++){
            while(!zero.empty()&&zero.front()<l)    zero.pop_front();
            int prev=l;
            for(int p=0; p<zero.size(); p++){
                int cnt0=p;
                int r=zero[p];
                if(cnt0>zmax)   break;
                int minlen=max(prev-l+1, cnt0*(cnt0+1));
                ans+=max(0, (r-l)-minlen+1);
                prev=r;
            }
        }
        return ans;
    }
};
