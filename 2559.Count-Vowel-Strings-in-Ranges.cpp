class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int m=queries.size();
        vector<int>pre(n+1,0);
        unordered_set<int>vowel={'a','e','i','o','u'};
        for(int i=0; i<n; i++){
            string cur=words[i];
            if(vowel.count(cur[0])&&vowel.count(cur[cur.size()-1])) pre[i+1]=pre[i]+1;
            else    pre[i+1]=pre[i];
        }
        vector<int>ans(m,0);
        for(int i=0; i<m; i++){
            ans[i]=pre[queries[i][1]+1] - pre[queries[i][0]];
        }
        return ans;
    }
};
