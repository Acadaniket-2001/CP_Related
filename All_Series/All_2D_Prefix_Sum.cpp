#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define rep(i,a,b) for(long long i=a;i<=b;i++)
#define rrep(i,a,b) for(long long i=a;i>=b;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define vll vector<ll>
#define vvl vector<vll>
#define p_q priority_queue
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// to get custom MOD(m), modify line no. 8
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_expo(ll a, ll n) { ll res = 1; while(n) { if(n % 2)   res = mod_mul(res, a), n--; else a  = mod_mul(a, a), n /= 2; } return res; }
ll mod_inv(ll a) { return mod_expo(a, MOD - 2); }   //MOD must be prime ; (a, MOD) -> coprime
ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)); }

/*-------------------> GY@@N KI BAATEIN <----------------------
1.  Try and prove ur solution, do not rely on intuition.
2.  Never over-optimise.
3.  Don't stick to 1 problem for long.
4.  Check other's solutions, especially those rated above you.
5.  Be humble, don't be fixated on your ideas.
* DO NOT GET STUCK ON ONE APPROACH
* DO NOT GET STUCK ON ONE APPROACH
* DO NOT GET STUCK ON ONE APPROACH.  
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

const int N = 1e3 + 7;
int v[N][N]; 
int pre[N][N];              //by default global array is initialised to '0'
void solve()
{
    ll n, m; cin >> n >> m;
    rep(i, 1, n) {          // attention!!!,  1 based indexing is used , think why -> 1D prefix sum
        rep(j, 1, m) {
            cin >> v[i][j];
        }
    }
    
    // calculating the 2D-prefix sum
    rep(i, 1, n) {
        rep(j, 1, m) {
            // assumption -> pre[x][y] has sum of all  elements of rectangle from (0, 0) to (x ,y)
            pre[i][j] = v[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }  
    
    //taking query
    int t; cin >> t;
    while(t--) {
        
        // (a, b) -> top left element of the rect.
        // (c, d) -> bottom right element of the rect.
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1] << endl;
    }  
}

// JUST ONE MISTAKE, AND YOU ARE HAHAHAHHHHHHHHHHAAAAAAAAAAAAAAA!!!
/* Wo sare problems karo jo lage ki ho jayega but nhi ho pata */

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

// Sample input 1
// 3 5
// 1 2 3 4 5
// 1 0 1 2 3
// 1 1 1 3 1
// 3
// 3 5 3 5
// 2 4 3 5
// 1 1 3 5
