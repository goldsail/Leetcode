class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        rear = new Node();
        head->prev = nullptr;
        head->next = rear;
        rear->prev = head;
        rear->next = nullptr;
    }
    
    int get(int key) {
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        } else {
            Node *node = hashMap.at(key);
            node->detach();
            node->putBehind(head);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if (hashMap.find(key) == hashMap.end()) {
            Node *node = new Node();
            node->key = key;
            node->val = value;
            node->putBehind(head);
            hashMap.insert(pair<int, Node*>(key, node));
            
            while (hashMap.size() > capacity) {
                Node *node = rear->prev;
                node->detach();
                hashMap.erase(node->key);
                delete node;
            }
        } else {
            Node *node = hashMap.at(key);
            node->val = value;
            node->detach();
            node->putBehind(head);
        }
    }
    
private:
    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
        
        void detach() {
            Node *temp1 = this->prev;
            Node *temp2 = this->next;
            temp1->next = temp2;
            temp2->prev = temp1;
            this->prev = nullptr;
            this->next = nullptr;
        }
        
        void putBehind(Node *node) {
            if (node != this) {
                Node *temp1 = node;
                Node *temp2 = node->next;
                temp1->next = this;
                this->prev = temp1;
                temp2->prev = this;
                this->next = temp2;
            }
        }
    };
    
    Node *head;
    Node *rear;
    
    unordered_map<int, Node*> hashMap;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */