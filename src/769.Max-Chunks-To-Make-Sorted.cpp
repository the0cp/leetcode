class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int vsum=0;
        int isum=0;
        int ans=0;
        int n=arr.size();
        for(int i=0; i<n; i++){
            if((vsum+=arr[i]) == (isum+=i)) ans++;
        }
        return ans;
    }
};
