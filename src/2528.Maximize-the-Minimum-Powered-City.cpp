class Solution {
public:
    vector<long long>diff;
    vector<long long>power;
    int n;

    bool check(long long target, int r, long long k){
        fill(diff.begin(), diff.end(), 0);
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=diff[i];
            long long curPower = power[i]+sum;
            if(curPower<target){
                long long need=target-curPower;
                k-=need;
                if(k<0) return false;
                sum+=need;  // L+need
                if(i+2*r+1<n) diff[i+2*r+1]-=need;    // R-need
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        n=stations.size();
        power.assign(n,0);
        diff.assign(n,0);

        vector<long long>prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+stations[i];
        }

        for(int i=0; i<n; i++){
            int left=max(0, i-r);
            int right=min(n-1, i+r);
            power[i]=prefix[right+1]-prefix[left];
        }

        long long low=*min_element(power.begin(), power.end());
        long long high=*max_element(power.begin(), power.end())+k;
        long long best=0;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid, r, k)){
                best=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return best;
    }
};
