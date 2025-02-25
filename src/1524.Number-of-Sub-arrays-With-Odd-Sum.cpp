class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum=0, even=0, odd=0, cnt=0;
        int mod=1e9+7;
        for(int num:arr){
            sum+=num;
            if(sum%2==1){
                odd++;
                cnt+=even+1;
            }else{
                even++;
                cnt+=odd;
            }
            cnt%=mod;
        }
        return cnt;
    }
};
