class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(;n && n%3!=2; n/=3);    return !n;
    }
};
