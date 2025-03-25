class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x, y;
        for(auto &rec:rectangles){
            x.push_back({rec[0],rec[2]});
            y.push_back({rec[1],rec[3]});
        }
        return check(x) || check(y);
    }

private:
    bool check(vector<vector<int>>&intervals){
        sort(intervals.begin(), intervals.end());
        int cnt=1;
        int max_end=intervals[0][1];
        for(auto &i:intervals){
            int st=i[0], end=i[1];
            if(max_end<=st) cnt++;
            max_end=max(max_end, end);
        }
        return cnt>=3;
    }
};
