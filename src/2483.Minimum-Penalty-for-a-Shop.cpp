class Solution {
public:
    int bestClosingTime(string customers) {
        int best=0;
        int minP=0;
        int prefix=0;
        for(int i=0; i<customers.length(); i++){
            prefix+=customers[i]=='Y'?-1:1;
            if(prefix<minP){
                best=i+1;
                minP=prefix;
            }
        }
        return best;
    }
};
