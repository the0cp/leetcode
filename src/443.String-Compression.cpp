class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        for(int i=0; i<chars.size();) {
            char letter=chars[i];
            int cnt=0;
            while(i<chars.size() && chars[i]==letter){
                cnt++;
                i++;
            }
            chars[idx++]=letter;
            if(cnt>1) for(char c:to_string(cnt)) chars[idx++]=c;
        }
        return idx;
    }
};
