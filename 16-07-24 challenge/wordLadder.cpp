class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
         //shortest path ->BFS algo
         queue<pair<string,int>>q;

        //instead of having vis array , we will have a set of strings
        unordered_set<string>st(wordList.begin(),wordList.end());
         
        //if element is visited , we will remove/erase that element from the set counting the no of steps
        q.push({beginWord,0});
        

        while(!q.empty()){
          string word= q.front().first;
          int steps= q.front().second;

          q.pop();

          if(word==endWord) return steps+1;

          //check for each combination 
          for(int i=0;i<word.length();i++){
            char original = word[i];
          for(char ch='a';ch<='z';ch++){
             word[i]= ch;

            if(st.find(word)!=st.end()){
              st.erase(word);
              q.push({word,steps+1});
              } 
            }
            word[i]=original;
          }
        }
        
        return 0;
    }
};