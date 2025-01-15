class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>>q;
        auto diff = [](int x, int y)->double{return (double)(x+1) / (y+1) - (double)x / y;};
        double ans=0;
        for(const auto& c:classes){
            int x=c[0], y=c[1];
            ans+=(double)x/(double)y;
            q.emplace(diff(x,y), x, y);
        }
        for(int i=0; i<extraStudents; i++){
            auto [d,x,y]=q.top();
            q.pop();
            ans+=d;
            q.emplace(diff(x+1, y+1), x+1, y+1);
        }
        return ans/classes.size();
    }
};
