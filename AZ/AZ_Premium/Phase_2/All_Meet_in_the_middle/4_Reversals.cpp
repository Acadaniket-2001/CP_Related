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

set<string> ans;

void gen(int lvl, string& s) {
    if(lvl == 2) {
        ans.insert(s);
        re;
    }

    f(i, 0, sz(s) - 1) {
        f(j, 0, sz(s) - 1) {
            reverse(s.begin() + i, s.begin() + j + 1);
            gen(lvl + 1, s);
            reverse(s.begin() + i, s.begin() + j + 1);
        }
    }
}

void solve()
{
    string s, t; cin >> s >> t;

    gen(0, s);
    set<string> sub0 = ans;
    ans.clear();

    gen(0, t);
    set<string> sub1 = ans;
    
    for(auto e: sub0) {
        if(sub1.find(e) != sub1.end()) {
            cout << "YES" << endl;
            re;
        }
    }

    cout << "NO" << endl;
}
//----------------------------------------------------------------------------------------------

void rec(int lvl, string &s, vector<string> & ans){
    if(lvl == 2) {
        ans.pb(s);
        re;
    }

    f(i, 0, sz(s) - 1) {
        f(j, i, sz(s) - 1) {
            reverse(s.begin() + i, s.begin() + j + 1);
            rec(lvl + 1, s, ans);
            reverse(s.begin() + i, s.begin() + j + 1);
        }
    }
}

vector<string> gene(string s) {
    vector<string> ans;
    rec(0, s, ans);
    sort(all(ans));
    return ans;
}

void solve1() {
    string s, t; cin >> s >> t;
    vector<string> s1 = gene(s);
    vector<string> t1 = gene(t);

    for(auto e: s1) {
        auto it = upper_bound(all(t1), e);
        if(it != t1.begin()) {
            it --;
            if(*it == e) {
                cout << "YES" << endl;
                re;
            }
        }
    }
    cout << "NO" << endl;
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

    int _t; cin >> _t; while(_t--)
    // solve();
    solve1();
    return 0;
}