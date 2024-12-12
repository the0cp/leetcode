class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>p;
        for(int i=0; i<gifts.size(); i++) p.push(gifts[i]);
        while(k--)
        {
            int temp=p.top();
            p.pop();
            p.push(sqrt(temp));
        }
        long long ans=0;
        while(!p.empty())
        {
            ans+=p.top();
            p.pop();
        }
        return ans;
    }
};
