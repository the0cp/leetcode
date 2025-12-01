class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total=accumulate(batteries.begin(), batteries.end(), 0LL);
        sort(batteries.begin(), batteries.end());

        for(int i=batteries.size()-1; i>=0; i--){
            if(batteries[i]>total/n){
                total-=batteries[i];
                n--;
            }else break;
        }
        return total/n;
    }
};
