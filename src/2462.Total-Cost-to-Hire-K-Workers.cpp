class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        if(candidates<<1>n){
            ranges::sort(costs);
            return accumulate(costs.begin(), costs.begin()+k, 0LL);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        for(int i=0; i<candidates; i++){
            pq.emplace(costs[i],i);
            pq.emplace(costs[n-i-1], n-i-1);
        }
        long long ans=0;
        int l=candidates;
        int r=n-candidates-1;
        while(k--){
            auto [c,i]=pq.top();
            pq.pop();
            ans+=c;
            if(l>r) continue;
            if(i<l) pq.emplace(costs[l],l++);
            else pq.emplace(costs[r],r--);
        }
        return ans;
    }
};
