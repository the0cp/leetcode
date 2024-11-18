class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum=0;
        int len=code.size();
        vector<int> v(len,0);
        if(k==0){
            return v;
        }
        if(k>0){
            for(int i=0; i<k; i++){
                sum+=code[i];
            }
            for(int i=0; i<len; i++){
                sum = sum-code[i]+code[(i+k)%len];
                v[i]=sum;
            }
        }else{
            for(int i=len+k; i<len; i++){
                sum+=code[i];
            }
            for(int i=len-1; i>=0; i--){
                int index=0;
                if(i+k<0){
                    index=(i+k+len)%len;
                }else{
                    index=(i+k);
                }
                sum=sum-code[i]+code[index];
                v[i]=sum;
            }
        }
        return v;
    }
};