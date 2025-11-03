class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int n=colors.size();
        int res=0;
        int left=neededTime[0];
        int sum=neededTime[0];
        for(int i=1; i<n; i++){
            int cur=neededTime[i];
            if(colors[i]==colors[i-1]){
                sum+=cur;
                left=max(left, cur);
            }else{
                res+=sum-left;
                sum=cur;
                left=cur;
            }
        }
        res+=sum-left;
        return res;
    }
};
