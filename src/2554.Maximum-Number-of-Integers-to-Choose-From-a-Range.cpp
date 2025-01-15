class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool>flag(n+1, false);
        for(int x:banned) if(x<=n) flag[x]=true;
        int res=0;
        long long sum=0;
        for(int i=1; i<=n; i++){
            if(!flag[i]){
                if(sum+i>maxSum)    break;
                res++;
                sum+=i;
            }
        }
        return res;
    }
};
