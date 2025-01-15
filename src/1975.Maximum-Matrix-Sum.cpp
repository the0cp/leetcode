class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int negative=0;
        int min_abs=INT_MAX;
        for(auto& row: matrix){
            for(int e: row){
                min_abs=min(min_abs, abs(e));
                if (e<0){
                    sum-=e;
                    negative++;
                }
                else{
                    sum+=e;
                }
            }
        }
        return (negative%2==1)?sum-2*min_abs:sum;
    }
};
