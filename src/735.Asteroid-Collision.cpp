class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for(int a:asteroids){
            while(!res.empty() && a<0 && res.back()>0){
                if(abs(a)>res.back()){
                    res.pop_back();
                    continue;
                }else if(abs(a)==res.back()){
                    res.pop_back();
                }
                a=0;
            }
            if(a!=0)    res.push_back(a);
        }
        return res;
    }
};
