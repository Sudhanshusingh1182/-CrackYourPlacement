class WordDictionary {
public:
    struct trieNode{
      bool isEndOfWord= false;
      trieNode* children[26];
    };

    trieNode* root;

    trieNode* getNode(){
      trieNode* newNode= new trieNode();
      
      newNode-> isEndOfWord = false;

      for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
      }

      return newNode;

    }

    WordDictionary() {
        root= new trieNode();
    }
    
    void addWord(string word) {
        trieNode* crawler= root;

        for(int i=0;i<word.length();i++){
          char ch = word[i];
          int idx= ch-'a';

          if(crawler->children[idx]==NULL) crawler->children[idx]= getNode();

          crawler= crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word, root);
    }

private:
    bool searchInNode(const string& word, trieNode* node, int index = 0) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] != nullptr && searchInNode(word, node->children[i], index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            return searchInNode(word, node->children[idx], index + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */