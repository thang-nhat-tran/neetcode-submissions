struct Node {
    int key, value;
    Node* left;
    Node* right;
    Node(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = nullptr;
    }
    
    int get(int key) {
        // cout << "GET: " << key << "\n";
        // cout << "HEAD: " << head->key << "\n\n"; 
        if (!cache.count(key)) return -1;
        Node* node = cache[key];
        // cout << "BEF: " << node->value << "\n";
        moveToTail(node);
        // cout << "AFT: " << node->value << "\n\n";
        return node->value;
    }
    
    void put(int key, int value) {

        Node* node = cache.count(key) ? cache[key] : new Node(key, value);
        node->value = value;
        moveToTail(node);
        cache[key] = node;
        
        if (cache.size() > this->capacity) {
            // cout << key << " " << value << "\n";
            // cout << "size: " << cache.size() << "\n";
            // cout << "del: " << head->key << "\n";
            cache.erase(head->key);
            // cout << "PUT: " << key << " " << value << "\n";
            // cout << "DEL: " << head->key << "\n\n";
            head = head->right;
        }
    }

    void moveToTail(Node* node) {
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        if (node == tail) return;
        if (node == head) {
            if (head == tail) return;
            // cout << "MOVE: " << node->key << "\n";
            head = head->right;
            // cout << "HEAD: " << head->key << "\n\n";
        }
        Node* left = node->left;
        Node* right = node->right;
        if (left != nullptr) left->right = node->right;
        if (right != nullptr) right->left = left;

        tail->right = node;
        node->left = tail;
        node->right = nullptr;
        tail = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */