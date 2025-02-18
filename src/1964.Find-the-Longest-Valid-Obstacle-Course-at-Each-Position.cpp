class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>dp;
        vector<int>ans;
        for(int i:obstacles){
            auto it=upper_bound(dp.begin(), dp.end(), i);
            if(dp.empty() || it==dp.end()){
                dp.push_back(i);
                ans.push_back(dp.size());
            }else{
                *it=i;
                ans.push_back(it-dp.begin()+1);
            }
        }
        return ans;
    }
};
