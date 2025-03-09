class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int ans=0, cnt=0;
        for(int i=0; i<n+k-1; i++){
            if(colors[i%n]==colors[(i+1)%n]) cnt=0;
            cnt++;
            ans+=cnt>=k;
        }
        return ans;
    }
};
