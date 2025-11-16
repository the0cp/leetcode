class Solution {
public:
    const long long mod=1e9+7;
    int numSub(string s) {
        int cnt=0;
        long long ans=0;
        for(char c:s){
            if(c=='0'){
                ans=ans+(long long)cnt*(cnt+1)/2%mod;
                cnt=0;
            }else{
                cnt++;
            }
        }
        ans=ans+(long long)cnt*(cnt+1)/2%mod;
        return ans;
    }
};
