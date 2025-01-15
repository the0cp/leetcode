class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length(); 
        vector<int>left(n+5, 0);
        vector<int>right(n+5, 0);
        vector<int>ans(n, 0);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 1; i <= n; i++){
            left[i] = cnt1 + left[i - 1];
            cnt1 += (boxes[i-1] - '0'); 
            right[n-i+1] = cnt2 + right[n-i+2];
            cnt2 += (boxes[n-i] - '0');
        } 
        for(int i = 1; i <= n; i++) ans[i-1] = left[i] + right[i];
        return ans;
    }
};
