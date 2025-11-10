class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>st(n+1, 0);
        int top=0;
        int ans=0;
        for(int n:nums){
            while(st[top]>n){
                top--;
                ans++;
            }
            if(st[top]!=n){
                top++;
                st[top]=n;
            }
        }
        return ans+top;
    }
};
