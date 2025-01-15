class Solution {
public:
    bool canChange(string start, string target) {
        string s=start;
        string t=target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());
        if(s!=t)    return false;
        for(int i=0, j=0; i<start.size(); i++){
            if(start[i]=='_')   continue;
            while(j<target.size()&&target[j]=='_')   j++;
            if(start[i]=='L'&&i<j)  return false;
            if(start[i]=='R'&&i>j)  return false;
            j++;
        }
        return true;
    }
};
