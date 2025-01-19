class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int l=0;
        int r=height.size()-1;
        int lmax=0;
        int rmax=height[r];
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<lmax)  water+=lmax-height[l];
                else    lmax=height[l];
                l++;
            }else{
                if(height[r]<rmax)  water+=rmax-height[r];
                else    rmax=height[r];
                r--;
            }
        }
        return water;
    }
};