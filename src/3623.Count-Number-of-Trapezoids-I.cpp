class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long mod=1e9+7;
        const long long n=points.size();
        unordered_map<int,int> freq;
        for(auto&p:points)  freq[p[1]]++;
        long long sum=0;
        long long z2=0;
        for(auto&[y,f]:freq){
            if(f<=1)    continue;
            const long long z=f*(f-1LL)/2LL;
            sum+=z;
            z2+=z*z;
        }
        long long ans=sum*sum-z2;
        ans/=2;
        ans%=mod;
        return ans;
    }
};
