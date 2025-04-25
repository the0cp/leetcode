class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, {}, [](auto &a){return a[1];});
        int pre=INT_MIN;
        int remain=0;
        for(auto p:intervals){
            if(p[0]>=pre){
                remain++;
                pre=p[1];
            }
        }
        return intervals.size() - remain;
    }
};
