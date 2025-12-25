class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int n=happiness.size();
        ranges::sort(happiness);
        long long sum=0;
        for(int i=0; i<k; i++){
            int cur=happiness[n-1-i];
            if(cur-i<=0)break; 
            sum+=(cur-i);
        }
        return sum;
    }
};
