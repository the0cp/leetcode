class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int f = 1;
        int n = derived.size();
        for(int i=0; i < n-1; i++)
            if(derived[i] == 1) f = -f;
        return derived[n-1] == 0 ? (f==1) : (f==-1);
    }
};
