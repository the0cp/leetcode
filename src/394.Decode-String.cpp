class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string cur="";
        int num=0;
        for(char c:s){
            if(isdigit(c))  num=num*10+(c-'0');
            else if(c=='['){
                st.push({cur,num});
                cur="";
                num=0;
            }
            else if(c==']'){
                auto [last,cnt]=st.top();
                st.pop();
                for(int i=0; i<cnt; i++)    last+=cur;
                cur=last;
            }
            else    cur+=c;
        }
        return cur;
    }
};
