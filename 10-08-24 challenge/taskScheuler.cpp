class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int mp[26]{};

        for(int i=0;i<tasks.size();i++) mp[tasks[i]-'A']++;

       sort(begin(mp),end(mp));

       int maxFreq= mp[25];
       int gadhe = maxFreq- 1;

       int idolSlots= n * gadhe;

       for(int i=24;i>=0;i--){
         idolSlots-= min(mp[i],gadhe);
       }

       if(idolSlots>0) return tasks.size()+ idolSlots;

       return tasks.size();
    }
};