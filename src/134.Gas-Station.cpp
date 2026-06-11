class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0;
        int total_cost=0;
        int cur_gas=0;
        int startp=0;

        for(int i=0; i<n; i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
            cur_gas+=(gas[i]-cost[i]);
            if(cur_gas<0){
                startp=i+1;
                cur_gas=0;
            }
        }

        return total_gas<total_cost?-1:startp;
    }
};