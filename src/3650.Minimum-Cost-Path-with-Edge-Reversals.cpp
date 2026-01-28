class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using State=tuple<long long, int, int>;
        vector<vector<pair<int,int>>>out(n), in(n);
        for(auto &e:edges){
            out[e[0]].push_back({e[1], e[2]});
            in[e[1]].push_back({e[0], e[2]});
        }
        vector<vector<long long>>dist(n, vector<long long>(2, LLONG_MAX));
        priority_queue<State, vector<State>, greater<State>>pq;
        dist[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [cost, u, used]=pq.top();
            pq.pop();
            if(cost>dist[u][used])  continue;
            for(auto [v,w]:out[u]){
                if(dist[v][0]>cost+w){
                    dist[v][0]=cost+w;
                    pq.push({dist[v][0], v, used});
                }
            }
            if(used==0){
                for(auto [v,w]:in[u]){
                    if(dist[v][0]>cost+2LL*w){
                        dist[v][0]=cost+2LL*w;
                        pq.push({dist[v][0], v, 0});
                    }
                }
            }
        }
        long long ans=min(dist[n-1][0], dist[n-1][1]);
        return ans==LLONG_MAX?-1:ans;
    }
};
