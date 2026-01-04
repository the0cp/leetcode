class Solution {
public:
    int factor(int n){
        int sum=0;
        int c=0;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                int j=n/i;
                if(j==i || c>0) return 0;
                sum+=i+j;
                c++;
            }
        }
        if(c==0)    return 0;
        return sum+n+1;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=factor(nums[i]);
        }
        return sum;
    }
};
