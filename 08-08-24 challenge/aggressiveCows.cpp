#include <bits/stdc++.h>
using namespace std;

// Problem Code/Link:

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define incr_loop(a, n) for (int i = a; i < n; i++)
#define decr_loop(a, b) for (int i = a; i > b; i--)
#define nested_incr_loop(a, b) for (int j = a; j < b; j++)
#define nested_decr_loop(a, b) for (int j = b; j > a; --j)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef set<int> si;
typedef set<char> scr;
typedef set<string> sst;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<char, int> mci;
typedef unordered_map<char, int> umci;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef pair<int, int> pii;
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define sort_all(v) sort(all(v));
#define PI 3.141592653589793238462
#define space cout << ' ';
#define gcd(a, b) __gcd(a, b);
#define all(x) x.begin(), x.end()
#define in(x) cin >> x;
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define in4(x, y, z, a) cin >> x >> y >> z >> a;
#define out(x) cout << x<<endl;
#define out2(x, y) cout << x << ' ' << y<<endl;
#define out3(x, y, z) cout << x << ' ' << y << ' ' << z<<endl;
#define out4(x, y, z ,a) cout << x <<' '<< y <<' '<< z<<' '<<a<<' '<< endl;
#define nl cout << endl;
#define ins(x) cin>>x
#define f first
#define s second
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
/**************Debugger*************/
void _print(int a){ cerr << a;}
void _print(long long a){ cerr << a;}
void _print(bool a){ cerr << a;}
void _print(char a){ cerr << a;}
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << "="; \
    _print(x);         \
    cout << endl;
#else
#define debug(x)
#endif
/************************************/

bool isPossible(vl &a ,ll n, ll c, ll mid){
    ll cnt=1;
    ll lastPos= a[0];

    incr_loop(1,n){  // Start loop from index 1
        if(a[i]-lastPos >= mid){
            cnt++;
            if(cnt == c) return true;
            lastPos = a[i];
        }
    }

    return false;
}

ll aggressiveCows(vl &a, ll c, ll n){
    sort_all(a);
    ll l = 1;  // Minimum distance can't be less than 1
    ll h = a[n-1] - a[0];  // Maximum possible distance

    ll ans = -1;

    while(l <= h){
        ll mid = l + (h-l)/2;

        if(isPossible(a, n, c, mid)){
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return ans;
}

void find_the_answer_bro(){
    ll n,c;
    in2(n,c);

    vl a(n);
    incr_loop(0,n) in(a[i]);

    ll ans = aggressiveCows(a, c, n);

    out(ans);
}
/************************************/
int main(){

#ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
#endif
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int tt = 1;
    in(tt);

    while (tt--){
        find_the_answer_bro();
    }

    return 0;
}
