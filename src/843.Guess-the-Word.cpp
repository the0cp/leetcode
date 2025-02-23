/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int getMatch(string a, string b){
        int match=0;
        for(int i=0; i<6; i++)  match += a[i]==b[i]?1:0;
        return match;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string>set(words.begin(), words.end());
        while(!set.empty()){
            string pop=*set.begin();
            int match=master.guess(pop);
            for(auto it=set.begin();it!=set.end();){
                if(match!=getMatch(*it,pop))    it=set.erase(it);
                else it++;
            }
            set.erase(pop);
        }
    }
};
