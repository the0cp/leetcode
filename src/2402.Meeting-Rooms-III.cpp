class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings);
        vector<int>cnt(n);
        priority_queue<int,vector<int>,greater<>>free;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>busy;

        for(int i=0; i<n; i++)  free.push(i);
        for(auto &m:meetings){
            long long s=m[0], d=m[1]-m[0];
            while(!busy.empty()&&busy.top().first<=s){
                free.push(busy.top().second);
                busy.pop();
            }
            if(!free.empty()){
                int r=free.top();
                free.pop();
                busy.push({m[1], r});
                cnt[r]++;
            }else{
                auto [e, r]=busy.top();
                busy.pop();
                busy.push({e+d, r});
                cnt[r]++;
            }
        }
        return ranges::max_element(cnt)-cnt.begin();
    }
};
