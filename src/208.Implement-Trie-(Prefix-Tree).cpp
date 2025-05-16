class Trie {
struct Node{
    Node *son[26]{};
    bool end=false;
};
public:
    Trie() {
        
    }

    Node* root=new Node();

    int find(string word){
        Node* cur=root;
        for(char c:word){
            c-='a';
            if(cur->son[c]==nullptr)    return 0;
            cur=cur->son[c];
        }
        return cur->end?2:1;
    }
    
    void insert(string word) {
        Node* cur=root;
        for(char c:word){
            c-='a';
            if(cur->son[c]==nullptr){
                cur->son[c]=new Node();
            }
            cur=cur->son[c];
        }
        cur->end=true;
    }
    
    bool search(string word) {
        return find(word)==2;
    }
    
    bool startsWith(string prefix) {
        return find(prefix)!=0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
