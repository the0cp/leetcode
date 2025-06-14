class LRUCache {
public:
    class Node{
    public:
        int key;
        int value;
        Node* left;
        Node* right;
        Node(int key, int value){
            this->key=key;
            this->value=value;
            this->left=nullptr;
            this->right=nullptr;
        }
    };

    void addHead(Node* node){
        node->left=head;
        node->right=head->right;
        head->right->left=node;
        head->right=node;
    }

    void deleteNode(Node* node){
        node->left->right=node->right;
        node->right->left=node->left;
    }

    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*>mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->head=new Node(-1,-1);
        this->tail=new Node(-1,-1);
        head->right=tail;
        tail->left=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            addHead(mp[key]);
            return mp[key]->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->value=value;
            deleteNode(mp[key]);
            addHead(mp[key]);
        }else{
            if(mp.size()==capacity){
                Node* toDelete=tail->left;
                deleteNode(toDelete);
                mp.erase(toDelete->key);
                delete(toDelete);
            }
            Node* newNode=new Node(key,value);
            addHead(newNode);
            mp[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
