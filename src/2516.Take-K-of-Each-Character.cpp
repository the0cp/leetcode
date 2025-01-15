class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int>cnt;
        for(char c:s){
            cnt[c]+=1;
        }
        if(cnt['a']<k||cnt['b']<k||cnt['c']<k){
            return -1;
        }
        int s_size=s.size();
        int left=0;
        int result;
        for(int right=0; right<s_size; right++){
            cnt[s[right]]-=1;
            while(cnt[s[right]]<k){
                cnt[s[left++]]+=1;
            }
            result=max(result, right-left+1);
        }
        return s.size()-result;
    }
};
