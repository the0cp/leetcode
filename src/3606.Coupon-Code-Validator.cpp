class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>e,g,p,r;
        for(int i=0; i<isActive.size(); i++){
            if(!isActive[i])    continue;
            string& bl=businessLine[i];
            if(bl!="electronics"&&bl!="grocery"&&bl!="pharmacy"&&bl!="restaurant")  continue;
            if(code[i].empty()) continue;

            bool valid=true;
            for(char c:code[i]){
                if(!isalnum(c)&&c!='_'){
                    valid=false;
                    break;
                }
            }
            if(!valid)  continue;
            switch(bl[0]){
                case 'e':   e.push_back(code[i]); break;
                case 'g':   g.push_back(code[i]); break;
                case 'p':   p.push_back(code[i]); break;
                case 'r':   r.push_back(code[i]); break;
            }
        }
        sort(e.begin(), e.end());
        sort(g.begin(), g.end());
        sort(p.begin(), p.end());
        sort(r.begin(), r.end());

        vector<string> ans;
        ans.insert(ans.end(), e.begin(), e.end());
        ans.insert(ans.end(), g.begin(), g.end());
        ans.insert(ans.end(), p.begin(), p.end());
        ans.insert(ans.end(), r.begin(), r.end());
        return ans;
    }
};
