class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k&1)==0||k%5==0)    return -1;
        if(k==1)    return 1;
        int n=1;
        for(int i=2;;i++){
            n=(n*10+1)%k;
            if(n==0)    return i;
        }
        return -1;
    }
};
