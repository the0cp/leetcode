class Solution {
public:
    int digSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int>mp;
        for(int i=1; i<=n; i++){
            mp[digSum(i)]++;
        }    
        int msize=0;
        for(auto&p:mp)  msize=max(msize, p.second);
        int res=0;
        for(auto&p:mp)  if(p.second==msize)  res++;
        return res;
    }
};
