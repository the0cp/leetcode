class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int>mp;
        for(char c:magazine){
            if(mp.find(c)==mp.end()){
                mp[c]=1;
            }else{
                mp[c]++;
            }
        }

        for(char c:ransomNote){
            if(mp.find(c)!=mp.end()&&mp[c]>0){
                mp[c]--;
            }else{
                return false;
            }
        }

        return true;
    }
};
