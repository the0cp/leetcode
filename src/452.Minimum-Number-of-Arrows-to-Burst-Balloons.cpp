class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ranges::sort(points, {}, [](const auto &p){return p[1];});
        long long pre=LLONG_MIN;
        int ans=0;
        for(auto p:points){
            if(p[0]>pre){
                ans++;
                pre=p[1];
            }
        }
        return ans;
    }
};
