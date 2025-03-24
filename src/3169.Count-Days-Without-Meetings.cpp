class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int today=0;
        sort(meetings.begin(), meetings.end());
        for(auto m:meetings){
            int i=m[0], j=m[1];
            if(j<=today)    continue;
            else if(i>today)    days-=j-i+1;
            else    days-=j-today;
            today=j;
        }
        return days;
    }
};
