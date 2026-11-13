class Solution {
public:
    struct TrieNode{
        TrieNode* next[2] = {nullptr, nullptr};
    };

    TrieNode* root = new TrieNode();
    int ans=0;

    void insert(int n){
        TrieNode* node = root;
        for(int i=30; i>=0; i--){
            int bit=(n>>i)&1;
            if(node->next[bit]==nullptr){
                node->next[bit]=new TrieNode();
            }
            node=node->next[bit];
        }
    }

    void query(int n){
        TrieNode* node= root;
        int cur=0;
        for(int i=30; i>=0; i--){
            int bit=(n>>i)&1;
            if(node->next[!bit]!=nullptr){
                cur|=(1<<i);
                node=node->next[!bit];
            }else{
                node=node->next[bit];
            }
        }
        ans=max(cur, ans);
    }

    int findMaximumXOR(vector<int>& nums) {
        for(int n:nums){
            insert(n);
            query(n);
        }
        return ans;
    }
};