class TrieNode {
public: 
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (auto &w : word) {
            int i = w - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i]; 
        }
        p->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode* p = root;
        for (auto &w : word) {
            int i = w - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix) return true;
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
