struct Node {
    int key, value;
    Node* left;
    Node* right;
    Node(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    void remove(Node* node) {
        if (node == head && node == tail) {
            head = tail = nullptr;
            return;
        }
        if (node == head) {
            head = head->right;

            return;
        }
        if (node == tail) {
            tail = tail->left;
            return;
        }

        if (node->left) node->left->right = node->right;
        if (node->right) node->right->left = node->left;
        if (node == head) head = head->right;
        if (node == tail) tail = tail->left;
    }
    void addToTail(Node* node) {
        if (!head) {
            head = tail = node;
            return;
        }
        node->left = tail;
        tail->right = node;
        tail = node;
    }   
public:
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = nullptr;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        addToTail(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key))
            remove(cache[key]);
        Node* node = new Node(key, value);
        addToTail(node);
        cache[key] = node;
        
        if (cache.size() > this->capacity) {
            Node* lru = cache[head->key];
            cache.erase(head->key);
            head = head->right;
            delete(lru);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */