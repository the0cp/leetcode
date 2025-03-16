class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int size = ranks.size();
        long long left = 1;
        long long right = *min_element(ranks.begin(), ranks.end()) * (1LL) * cars * cars;
        while(left<right){
            long long mid = left + (right - left) / 2;
            long long curCars = 0;
            for(int i=0; i<size; i++) curCars += sqrt(mid / ranks[i]);
            if(curCars >= cars) right=mid;
            else left = mid+1;
        }
        return left;
    }
};
