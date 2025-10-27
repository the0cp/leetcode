class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0, prev=0;
        for(string &row:bank){
            int cnt=count(row.begin(), row.end(), '1');
            if(cnt>0){
                ans+=cnt*prev;
                prev=cnt;
            }
        }
        return ans;
    }
};
