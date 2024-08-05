class Trie {
public:
    struct trieNode{
       bool isEndOfWord;
       trieNode* children[26];
    };

    trieNode* root;

    trieNode* getNode(){
      trieNode* newNode = new trieNode();

      newNode->isEndOfWord= false;

      for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
      }

      return newNode;
    }

    Trie() {
        root= getNode();
    }
    
    void insert(string word) {
        trieNode* crawler =  root;
        
        for(int i=0;i<word.length();i++){
          char ch= word[i];
          int idx= ch-'a';

          if(crawler->children[idx]==NULL) crawler->children[idx]= getNode();

          crawler= crawler->children[idx];
        }

        //atlast , mark the endOfWord as true
        crawler->isEndOfWord= true;
        
    }
    
    bool search(string word) {
        trieNode* crawler =  root;
        
        for(int i=0;i<word.length();i++){
          char ch= word[i];
          int idx= ch-'a';

          if(crawler->children[idx]==NULL) return false;

          crawler= crawler->children[idx];
        }

        if(crawler!=NULL && crawler->isEndOfWord == true) return true;

        return false;


    }
    
    bool startsWith(string word) {
        trieNode* crawler =  root;
        
        int i=0;

        for(i;i<word.length();i++){
          char ch= word[i];
          int idx= ch-'a';

          if(crawler->children[idx]==NULL) return false;

          crawler= crawler->children[idx];
        }

        if(i==word.length()) return true;

        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */