class Solution {
public:
    bool validPalindrome(string s) {
        int diff_cnt=0;
        int diff_cnt2=0;
        int i=0,j=s.length()-1;

        while(i<=j){
          if(s[i]==s[j]) i++,j--;

          else {
            diff_cnt++;
            j--;
          }
        }
        
        i=0,j=s.length()-1;

        while(i<=j){
          if(s[i]==s[j]) i++,j--;

          else {
            diff_cnt2++;
            i++;
          }
        }


        return diff_cnt<=1 || diff_cnt2<=1 ;
    }
};