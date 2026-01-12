class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        vector<int>prev=points[0];
        for(auto&p:points){
            ans+=max(abs(p[0]-prev[0]), abs(p[1]-prev[1]));
            prev=p;
        }
        return ans;
    }
};
