class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>in(n,0);
        vector<int>maxChain(n,0);
        for(int x:favorite) in[x]++;
        deque<int>dq;
        for(int i=0; i<n; i++)  if(in[i]==0)  dq.push_back(i);
        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            int next=favorite[cur];
            maxChain[next]=max(maxChain[next], maxChain[cur]+1);
            if(--in[next]==0)   dq.push_back(next);     // pre nodes have all been processed
        }
        int circle=0;
        int chain=0;
        for(int i=0; i<n; i++){
            if(in[i]==0)    continue;
            int cur=favorite[i];
            int size=1;
            while(cur!=i){
                in[cur]=0;
                cur=favorite[cur];
                size++;
            }   // count circle size
            if(size==2) chain += 2+maxChain[i]+maxChain[favorite[i]];
            else    circle=max(circle,size);
        }
        return max(circle, chain);
    }
};