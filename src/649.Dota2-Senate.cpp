class Solution {
public:
    string predictPartyVictory(string senate) {
        int flag=0;
        for(int i=0; i<senate.size(); i++){
            if(senate[i]=='R' && flag++<0)  senate.push_back('D');
            if(senate[i]=='D' && flag-->0)  senate.push_back('R');
        }
        return flag>0?"Radiant":"Dire";
    }
};
