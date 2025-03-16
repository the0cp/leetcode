class Solution {
public:
    int maxSum(vector<int>& nums){
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        set<int> s(nums.begin(), nums.end());
        vector<int> sorted(s.begin(), s.end());

        int sum = 0;
        bool neg = true;

        for(int num : sorted){
            if(num > 0){
                sum += num;
                neg = false;
            }
        }

        if(neg){
            return sorted.back();
        }else{
            return sum;
        }
    }
};
