class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int x0=complexity[0];
        const int x1=*min_element(complexity.begin()+1, complexity.end());
        const int mod=1e9+7;
        const int n=complexity.size();

        if(x0>=x1)  return 0;
        long long cnt=1;
        for(int i=1; i<=n-1; i++){
            cnt*=i;
            if(cnt>=mod)    cnt%=mod;
        }
        return cnt;
    }
};
