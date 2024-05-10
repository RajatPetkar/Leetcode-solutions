class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            for (int j = 0; j < 26; ++j) {
                if (curr->children[j] != nullptr && j != index) {
                    string temp = word;
                    temp[i] = 'a' + j;
                    if (searchHelper(curr->children[j], temp, i + 1)) {
                        return true;
                    }
                }
            }
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return false;
    }

private:
    bool searchHelper(TrieNode* node, string& word, int index) {
        TrieNode* curr = node;
        for (int i = index; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
};

class MagicDictionary {
public:
     Trie* trie;
    MagicDictionary() {
                trie = new Trie();

    }
    
    void buildDict(vector<string> dictionary) {
        for (const string& word : dictionary) {
            trie->insert(word);
        }
    }
    
    bool search(string searchWord) {
                return trie->search(searchWord);

    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */