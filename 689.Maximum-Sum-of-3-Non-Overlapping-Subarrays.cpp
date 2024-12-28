class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>sum;
        int cur=0;
        for(int i=0; i<k; i++)  cur+=nums[i];
        sum.push_back(cur);
        for(int i=k; i<n; i++){
            cur+=nums[i]-nums[i-k];
            sum.push_back(cur);
        }
        int m=sum.size();
        vector<int>left(m,0);
        vector<int>right(m,m-1);
        for(int i=1; i<m; i++)    left[i] = sum[i]>sum[left[i-1]] ? i : left[i-1];
        for(int i=m-2; i>=0; i--)   right[i] = sum[i]>=sum[right[i+1]] ? i : right[i+1];
        int max=0;
        vector<int>ans(3);
        for(int i=k; i<m-k; i++){
            if(max < sum[i]+sum[left[i-k]]+sum[right[i+k]]){
                max = sum[i]+sum[left[i-k]]+sum[right[i+k]];
                ans = {left[i-k], i, right[i+k]};
            }
        }
        return ans;
    }
};
