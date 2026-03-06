class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int n0=s.find('0');
        if(n0==-1)  return 1;
        int n1=s.find_last_of('1');
        return n0>n1;
    }
};
