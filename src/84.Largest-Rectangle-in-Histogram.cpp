class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
