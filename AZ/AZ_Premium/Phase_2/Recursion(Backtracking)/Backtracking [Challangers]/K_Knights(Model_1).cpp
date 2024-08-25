#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f(i,a,b) for(long long i=a;i<=b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define P 1000000007
#define P1 998244353
#define llINT_MAX 9e18
#define iINT_MAX 1e9
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mkp make_pair
#define ff first
#define ss second
#define vii vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define p_q priority_queue
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define yes cout << "Yes" << "\n"
#define no cout << "No" << "\n"
#define gg cout << -1 << "\n"
#define ln cout << "\n"
#define re return
template <class T> istream& operator >> (istream &is, vector<T> &v) { for(auto &i : v)    is >> i; return is; };
template <class T> ostream& operator << (ostream &os, vector<T> &v) { for(auto &i : v)    os << i << " "; cout << "\n"; return os; };
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif
long long POW(long long a,long long b){return (long long)(pow(a,b)+0.5);}
long long gcd(long long a,long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return (a*b)/__gcd(a,b);}
long long Ceil(long long a,long long b){return (a+b-1)/b;}
long long Sqrt(long long x){ long long y=sqrt(x)+5;while(y*y>x)y--;return y;}
long long sq(long long x){return (1ll*x*x);}
/*-------------------> Greedy / Constructive <----------------------
                        D T D P G B
⭐ D -> Decode the operation
⭐ T -> Think in reverse
⭐ D -> Dimensional Setup
⭐ P -> Prefix or Suffix ideas
⭐ G -> Greedy / Sorting
⭐ B -> Bit Manipulation
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int n, k; 
set<pair<int, int>> pos;
pair<int, int> last;
int dr[] = {-2, -2, 2, 2, 1, -1, 1, -1}; 
int dc[] = {-1, 1, 1, -1, 2, 2, -2, -2};

bool can_place(int r, int c) {
    if(pos.find({r, c}) != pos.end())   return 0;
    f(i, 0, 7) {
        int ar = r + dr[i], ac = c + dc[i];
        if(ar >= 0 and ar < n and ac >= 0 and ac < n and pos.find({ar, ac}) != pos.end())   return 0;
    }
    return 1;
}

bool is_beyond_last_placed(int r, int c) {
    return ((r == last.ff and c > last.ss) or (r > last.ff));
}

int rec(int level) {
    if(level == k) {
        return 1;
    }

    // choices: O(N^2)
    int cnt = 0;
    f(r, last.ff, n - 1) {
        f(c, 0, n - 1) {
            if(can_place(r, c) and is_beyond_last_placed(r, c)) {
                pos.insert({r, c});
                pair<int, int> t = last;
                last = {r, c};

                cnt += rec(level + 1);
                
                pos.erase({r, c});
                last = t;
            }
        }
    }
    return cnt;
}

void solve()
{
    cin >> n >> k;
    last = {0, -1};
    cout << rec(0) << endl;
}

void trick() {
    // if k = 2.    a(n) = (n - 1)*(n + 4)*(n^2 - 3*n + 4)/2.   --> OEIS  ----> can be used for stress testing codes
    int N, K; cin >> N >> K;
    cout << (N - 1)*(N + 4)*(N*N - 3*N + 4)/2 << endl;       
}

int main()
{
    fastio();
    int _t; cin >> _t; while(_t--)
    solve();
    // trick();
    return 0;
}