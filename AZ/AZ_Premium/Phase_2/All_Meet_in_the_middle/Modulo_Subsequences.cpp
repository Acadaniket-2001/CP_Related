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

vector<ll> v;
ll n, m;

//method 1
// set<ll> generate(vector<int>& v) {
//     int n = v.size();
//     set<ll> ans;
//     f(mask, 0, (1LL << n) - 1) {
//         ll curr = 0;
//         f(j, 0, n - 1) {
//             if((mask >> j) & 1)     curr = (curr + v[j] % m) % m;
//         }
//         ans.insert(curr);
//     }
//     return ans;
// }

//method 2
set<ll> curr;
ll curr_sum = 0;
void rec(int lvl, vector<int>& v) {
    if(lvl == v.size()) {
        curr.insert(curr_sum);
        re;
    }

    rec(lvl + 1, v);

    curr_sum += v[lvl];
    rec(lvl + 1, v);
    curr_sum -= v[lvl];
}
set<ll> generate(vector<int>& v) {
    rec(0, v);
    set<ll> ans = curr;
    curr.clear();
    return ans;
}


void solve()
{
    cin >> n >> m;
    v.resize(n);    cin >> v;

    vector<int> newvec[2];
    f(i, 0, n - 1) 
        newvec[i&1].pb(v[i]);

    set<ll> sub0 = generate(newvec[0]); 
    set<ll> sub1 = generate(newvec[1]); 
    
    ll ans = 0;

    // method1:
    auto it = sub0.begin(); 
    auto rit = sub1.rbegin();
    while(it != sub0.end() and rit != sub1.rend()) {
        ll sum = (*it + *rit);
        ans = max(ans, sum % m);
        if(sum >= m)    rit++;
        else    it++;
    } 

    // method2: 
    // for(auto e: sub0) {
    //     auto it = sub1.lower_bound(m - e);
    //     if(it != sub1.begin()) {
    //         it --;  
    //         ans = max(ans, e + *it);
    //     }
    // }

    cout << ans;
}

// JUST ONE MISTAKE, AND YOU ARE HAHAHAHHHHHHHHHHAAAAAAAAAAAAAAA!!!
/* Wo sare problems karo jo lage ki ho jayega but nhi ho pata */

int main()
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