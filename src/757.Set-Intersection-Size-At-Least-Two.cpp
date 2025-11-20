class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&x, const vector<int>&y){
            return x[1]==y[1]?x[0]>y[0]:x[1]<y[1];
        });
        int st=-1;
        int end=-1;
        int cnt=0;
        for(auto i:intervals){
            int l=i[0];
            int r=i[1];
            if(l>end){
                st=r-1;
                end=r;
                cnt+=2;
            }else if(l>st){
                st=end;
                end=r;
                cnt++;
            }
        }
        return cnt;
    }
};
