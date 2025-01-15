class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        int ans=0, x=0;
        for(int i=0; i<events.size(); i++){
            int start=events[i][0];
            int end=events[i][1];
            int value=events[i][2];
            while(!q.empty() && q.top().first<start){
                x=max(x, q.top().second);
                q.pop();
            }
            ans=max(ans, x+value);
            q.emplace(end, value);
        }
        return ans;
    }
};
