class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1<n2)   return maxDotProduct(nums2, nums1);
        vector<int>cur(n2+1, INT_MIN);
        vector<int>next(n2+1, INT_MIN);
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int x=nums1[i]*nums2[j];
                int curMax=x;
                if(next[j+1]!=INT_MIN)  curMax=max(curMax, x+max(0, next[j+1]));
                curMax=max(curMax, cur[j+1]);
                curMax=max(curMax, next[j]);
                cur[j]=curMax;
            }
            next=cur;
        }
        return cur[0];
    }
};
