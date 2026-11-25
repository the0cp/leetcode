class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        const uint64_t BASE=100003;
        auto found=[&](vector<int>& nums, int k){
            unordered_map<uint64_t, int> count;
            uint64_t power=1;
            uint64_t hash=0;

            for(int i=0; i<k-1; i++) power*=BASE;
            for(int i=0; i<k; i++) hash=hash*BASE+nums[i];

            count[hash]++;

            for(int i=k; i<n; i++){
                hash-=nums[i-k]*power;
                hash*=BASE;
                hash+=nums[i];
                count[hash]++;
            }
            
            for(auto& [key, freq] : count) if(freq==1) return true;
            return false;
        };

        int left=1;
        int right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(found(nums, mid))
                right=mid;
            else
                left=mid+1;
        }

        return right;
    }
};
