class Solution{
public:
    
    struct trieNode{
      bool isEndOfWord;
      trieNode* children[26];
      
      trieNode(){
          isEndOfWord= false;
          for(int i=0;i<26;i++){
              children[i]=NULL;
          }
      }
    };
    
    trieNode* root = new trieNode();
    
    void insert(string word){
        trieNode* crawler= root;
        
        for(int i=0;i<word.length();i++){
            char ch= word[i];
            int idx= ch-'a';
            
            if(crawler->children[idx]==NULL) crawler->children[idx]=new trieNode();
            
            crawler= crawler->children[idx];
        }
        
        crawler->isEndOfWord= true;
    }
    
    void printSuggestions(trieNode* curr , vector<string>&temp , string& prefix){
        
        //recursively kr lenge  
        if(curr->isEndOfWord){
            temp.push_back(prefix);
            
        }
        
        for(char ch= 'a'; ch<='z';ch++){
            
            trieNode* next = curr->children[ch-'a'];
            
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggestions(string str){
        trieNode* prev = root;
        
        vector<vector<string>> output;
        
        string prefix= "";
        
        for(int i=0;i<str.length();i++){
            char lastCh = str[i];
            
            prefix.push_back(lastCh);
            
            //check for lastCh
            trieNode* curr= prev->children[lastCh-'a'];
            
            //if not found
            if(curr==NULL) break;
            
            //if found
            vector<string>temp;
            printSuggestions(curr,temp,prefix);
            
            output.push_back(temp);
            //temp.clear();
            prev=curr;
            
        }
        
        while(output.size()< str.length()) output.push_back({"0"});
        
        return output;
    }

  
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        for(int i=0;i<n;i++){
            insert(contact[i]);
        }
        
        //for(auto it: contact) insert(it);
        
        return getSuggestions(s);
        
    }
};