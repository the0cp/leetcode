class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        ranges::sort(events, {}, [](auto& e){return pair(stoi(e[1]), e[0][2]);});
        vector<int>ans(numberOfUsers);
        vector<int>online(numberOfUsers);
        for(auto&e:events){
            int cur=stoi(e[1]);
            string& mention=e[2];
            if(e[0][0]=='O'){
                online[stoi(mention)]=cur+60;
            }else if(mention[0]=='A'){
                for(int&t:ans)  t++;
            }else if(mention[0]=='H'){
                for(int i=0; i<numberOfUsers; i++){
                    if(online[i]<=cur)  ans[i]++;
                }
            }else{
                for(const auto&u:mention | ranges::views::split(' ')){
                    string s(u.begin()+2, u.end());
                    ans[stoi(s)]++;
                }
            }
        }
        return ans;
    }
};
