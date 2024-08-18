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

// #define int ll

int num; 
int max_digits_allowed;
int a, b;


int pow(int a, int b) {
    if(b == 0)  return 1;
    int ans = 1;
    f(i, 1, b) {
        ans *= a;
    }
    return ans;
}

bool isPrime(int x) {
    if(x == 0 or x == 1)    return 0;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0)  return 0;
    }
    return 1;
}

int rec(int lvl) {

    // debug(lvl, lvl, num)
    
    if(lvl > (max_digits_allowed + 1) / 2 - 1) {
        if(num >= a and num <= b and isPrime(num))  {
            // cout << num << endl;
            return 1;
        } 
        else return 0;
    }

    // lvl <= max_dig+1 / 2 - 1;
    int cnt = 0;
    f(k, 0, 9) {
        if(lvl == 0 and k == 0) continue;

        num += k * pow(10, lvl);
        if(lvl != max_digits_allowed - lvl - 1)    num += (k * pow(10, max_digits_allowed - lvl - 1));

        cnt += rec(lvl + 1);

        num -= k * pow(10, lvl);
        if(lvl != max_digits_allowed - lvl - 1)     num -= k * pow(10, max_digits_allowed - lvl - 1);
    }
    return cnt;
}

void solve()
{
    cin >> a >> b;
    int mnd = sz(to_string(a));
    int mxd = sz(to_string(b));

    int ans = 0;
    f(digits, mnd, mxd) {
        max_digits_allowed = digits;
        num = 0;
        ans += rec(0);
    }
    cout << ans << endl;
}

signed main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("io/Error.txt", "w", stderr);
        // freopen("io/Input.txt", "r", stdin);
        // freopen("io/Output.txt", "w", stdout);
    #endif

    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}
