class TrieNode {
private:
    unordered_map<char, TrieNode*> children;
    bool isWord;

public:
    TrieNode() {
        isWord = false;
    }

    friend class WordDictionary;
};  

class WordDictionary {
private: 
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(const auto& c : word) {
            if(!node->children.contains(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return help_search(0, word, root);
    }

private:
    bool help_search(int start, const string& word, TrieNode* node) {
        for(int i = start; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(const auto& p : node->children) {
                    TrieNode* child = p.second;
                    if(help_search(i+1, word, child))
                        return true;
                }
                // return false;
            }
            if(!node->children.contains(c))
                return false;
            
            node = node->children[c];
        }
        return node->isWord;
    }
};
