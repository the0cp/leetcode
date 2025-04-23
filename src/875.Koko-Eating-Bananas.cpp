class Solution {
public:
    int getime(vector<int>&piles, int speed){
        int hour=0;
        for(int i=0; i<piles.size(); i++)   hour+=ceil((double)piles[i]/speed);
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(), piles.end());
        int low=1;
        while(low<high){
            int mid=(low+high)>>1;
            if(getime(piles, mid)>h)    low=mid+1;
            else    high=mid;
        }
        return low;
    }
};
