class Trie {
struct Node{
    Node *son[26]{};
    vector<string>words;
};
public:
    Trie() {
        
    }

    Node* root=new Node();
    
    void insert(string word) {
        Node* cur=root;
        for(char c:word){
            c-='a';
            if(cur->son[c]==nullptr){
                cur->son[c]=new Node();
            }
            cur=cur->son[c];
            cur->words.push_back(word);
        }
    }
    
    vector<string> startsWith(string prefix) {
        Node*cur=root;
        for(auto p:prefix){
            p-='a';
            if(cur->son[p]==nullptr)    return {};
            cur=cur->son[p];
        }
        if(cur->words.size()<=3)    return vector<string>(cur->words.begin(), cur->words.end());
        else return vector<string>(cur->words.begin(), cur->words.begin()+3);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        ranges::sort(products);
        Trie*root=new Trie();
        for(auto p:products){
            root->insert(p);
        }
        vector<vector<string>>res;
        for(int i=0; i<searchWord.size(); i++){
            res.push_back(root->startsWith(searchWord.substr(0,i+1)));
        }
        return res;
    }
};
