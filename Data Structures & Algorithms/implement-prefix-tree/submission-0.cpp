class TrieNode {
private:
    TrieNode* children[26];
    bool isWord;

public:
    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    friend class PrefixTree;
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        for(auto&& c : word) {
            if(!currNode->children[c - 'a']) {
                currNode->children[c - 'a'] = new TrieNode();
            }
            currNode = currNode->children[c - 'a'];
        }
        currNode->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for(auto&& c : word) {
            if(!currNode->children[c - 'a'])
                return false;
            currNode = currNode->children[c - 'a'];
        }
        return currNode->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for(auto&& c : prefix) {
            if(!currNode->children[c - 'a'])
                return false;
            currNode = currNode->children[c - 'a'];
        }
        return true;
    }
};
