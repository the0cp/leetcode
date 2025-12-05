class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        if(n==1)    return 0;
        int l=0;
        int r=n-1;
        while(directions[l]=='L')   l++;
        while(l<r&&directions[r]=='R')  r--;
        if(l>=r)    return 0;
        return count_if(directions.begin()+l, directions.begin()+r+1, [](char c){return c!='S';});
    }
};
