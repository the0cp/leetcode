class Solution {
public:
    int maxArea(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        int res=0;
        for(int i=0; i<=n; i++){
            int h=(i==n)?0:heights[i];
            while(!st.empty()&&h<heights[st.top()]){
                int maxh=heights[st.top()];
                st.pop();
                int w=st.empty()?i:i-st.top()-1;
                res=max(res, maxh*w);
            }
            st.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        if(m==0)    return 0;
        vector<int>heights(n,0);
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0') heights[j]=0;
                else heights[j]++;
            }
            ans=max(ans, maxArea(heights));
        }
        return ans;
    }
};
