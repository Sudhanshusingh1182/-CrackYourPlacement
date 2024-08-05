class Solution {
public:
    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
        
        trieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    trieNode* root = new trieNode();

    void insert(string& word) {
        trieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = new trieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }

    bool solve(const string& str, int s) {
        if (s >= str.length()) return true;

        trieNode* curr = root;
        for (int i = s; i < str.length(); ++i) {
            int idx = str[i] - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
            if (curr->isEndOfWord) {
                if (solve(str, i + 1)) return true;
            }
        }
        return false;
    }

    int wordBreak(string A, vector<string>& B) {
        // Insert all words into the trie
        for (string& word : B) {
            insert(word);
        }
        // Check if the string can be segmented
        return solve(A, 0) ? 1 : 0;
    }
};