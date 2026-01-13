class Solution {
public:
    static double area(vector<vector<int>>&squares, const double y){
        double s=0;
        for(auto&sq:squares){
            double l=sq[2], y0=sq[1]+l;
            if(y>=y0)   continue;
            double h=min(l, y0-y);
            s+=l*h;
        }
        return s;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double s0=area(squares, -1e9);
        double shalf=s0/2.0;
        double minY=INT_MAX, maxY=INT_MIN;
        for(auto&sq:squares){
            double l=sq[2], y0=sq[1];
            minY=min(minY, y0);
            maxY=max(maxY, y0+l);
        }
        double l=minY, r=maxY, m;
        const double eps=1e-5;
        while(r-l>eps){
            m=l+(r-l)/2;
            double a=area(squares, m);
            if(a>shalf)    l=m;
            else r=m;
        }
        return l;
    }
};
