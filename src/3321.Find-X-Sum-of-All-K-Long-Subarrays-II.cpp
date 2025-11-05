class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<long long>ans;
        unordered_map<int, int>curCnt;
        set<pair<long long, int>, greater<pair<long long, int>>> top, bottom;

        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            long long cnt=curCnt[nums[i]];
            if(cnt>0){
                if(top.count({cnt, nums[i]})){
                    top.erase({cnt, nums[i]});
                    sum-=cnt*nums[i];
                }else{
                    bottom.erase({cnt, nums[i]});
                }
            }
            curCnt[nums[i]]=++cnt;
            top.insert({cnt, nums[i]});
            sum+=cnt*nums[i];

            if(top.size()>x){
                auto it_small=prev(top.end());
                sum-=it_small->first*it_small->second;
                bottom.insert({it_small->first, it_small->second});
                top.erase(it_small);
            }

            if(i>=k){
                long long cnt=curCnt[nums[i-k]];
                if(top.count({cnt, nums[i-k]})){
                    sum-=cnt*nums[i-k];
                    top.erase({cnt, nums[i-k]});
                }else{
                    bottom.erase({cnt, nums[i-k]});
                }

                curCnt[nums[i-k]]=--cnt;
                if(cnt>0){
                    bottom.insert({cnt, nums[i-k]});
                }

                if(top.size()<x){
                    auto it=bottom.begin();
                    if(it!=bottom.end()){
                        sum+=it->first*it->second;
                        top.insert({it->first,it->second});
                        bottom.erase(it);
                    }
                }
            }
            if(i+1>=k)  ans.push_back(sum);
        }
        return ans;
    }
};
