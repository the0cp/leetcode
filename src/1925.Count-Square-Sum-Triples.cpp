class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int m=2; m*m<n; m++){
            for(int k=1; k<m; k++){
                if(gcd(m,k)==1&&(m-k)%2==1){
                    int c=m*m+k*k;
                    if(c>n) break;
                    cnt+=2*(n/c);
                }
            }
        }
        return cnt;
    }
};
