const int nax = 1e5 + 2;
int power[nax];
class Solution{
   public:
   const static int prime = 93;
   const static int mod = 1e9 + 7;
   int hash(char ch, int index) {
       return ((long long) ch * power[index + 1]) % mod;
   }
   string longest(string s, int HA[]) {
       int n = (int) s.length() / 2;
       // cout << n << '\n';
       for(int i = n; i > 0; i --) {
           int hash_first = (0LL + HA[i - 1] - HA[0] + hash(s[0], 0)) % mod;
           int hash_second = (0LL + HA[2 * i - 1] - HA[i] + hash(s[i], i)) % mod;
           hash_first = (1LL * hash_first * power[i]) % mod;
           if(hash_first < 0) hash_first += mod;
           if(hash_second < 0) hash_second += mod;
           if(hash_first == hash_second) {
               string answer = longest(s.substr(0, i), HA);
               answer.push_back('*');
               for(int j = 2 * i; j < (int) s.length(); j ++) answer.push_back(s[j]);
               return answer;
           }
       }
       return s;
   }
   string compress(string s)
   {
       long long int p = 1;
       for(int i = 0; i < nax; i ++) {
           power[i] = p;
           p = (p * prime) % mod;
       }
       int HA[s.length()];
       HA[0] = hash(s[0], 0);
       for(int i = 1; i < (int) s.length(); i ++) {
           HA[i] = (0LL + HA[i - 1] + hash(s[i], i)) % mod;
       }
       return longest(s, HA);
   }
};