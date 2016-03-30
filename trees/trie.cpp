// LeetCode 208 - Implement Trie (Prefix Tree)

class TrieNode {
public:

    // Initialize your data structure here.
    int value;
    TrieNode* children[26];
    
    TrieNode() {
        value = 0;
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        int count = 0;
        for (int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if (!p->children[idx]){
                p->children[idx] = new TrieNode();
            }
            p = p->children[idx];
            count++;
        }
        p->value = count;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root; 
        for (int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if (p->children[idx])
                p = p->children[idx];
            else
                return false;
        }
        
        if (p->value != 0)
            return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root; 
        for (int i=0; i<prefix.length(); i++){
            int idx = prefix[i] - 'a';
            
            if(p->children[idx])
                p = p->children[idx];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
