class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,n=s.length();
        int maxLen=0;
        int maxFreq= 0; 
        int hash[26]= {0};

        while (j < n){
            hash[s[j] - 'A']++;  
            maxFreq = max(maxFreq, hash[s[j]-'A']);  

           
            while (j - i + 1 - maxFreq > k) {
                hash[s[i] - 'A']--;  
                i++;  
            }

            maxLen = max(maxLen, j - i + 1);  
            j++;  
        }

        return maxLen;
    }
};