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

// Problem : Given a running stream of integers, find the min. cost to equalise the elements 
//           present till now.

struct bag {
    ll suml = 0, sumr = 0;
    multiset<int> l, r;

    void rebalance() {
        // rebalance
        while(l.size() > r.size() + 1) {                  // if() -> also works
            auto it = l.end(); it--;                      // l-> top to r
            int val = *it;
            
            l.erase(it);
            suml -= val;

            r.insert(val);
            sumr += val;
        }
        while(l.size() < r.size()) {
            suml += *r.begin();
            l.insert(*r.begin());

            sumr -= *r.begin();
            r.erase(r.begin());
        }
    }

    void insert(int x) {
        if(!sz(l)) {
            l.insert(x);
            suml += x;
            re;
        }

        if(x < *l.rbegin()) {
            l.insert(x);
            suml += x;
        }
        else {
            r.insert(x);
            sumr += x;
        }
        rebalance();
    }

    void remove(int x) {
        if(x <= *l.rbegin()) {
            if(l.find(x) != l.end()) {
                l.erase(l.find(x));
                suml -= x;
            }
        }
        else {
            if(r.find(x) != r.end()) {
                r.erase(r.find(x));
                sumr -= x;
            }
        }
        rebalance();
    }

    ll cost() {
        ll med = *(l.rbegin());
        ll ans = (sz(l)*med) - suml;
        ans += sumr - (sz(r)*med);
        return ans;
    }
};


void solve()
{
    struct bag bg;

    bg.insert(2);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;

    bg.insert(3);
    bg.insert(5);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;

    bg.insert(7);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;

    bg.insert(9);
    bg.insert(11);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;

    bg.remove(2);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;
    
    bg.insert(1);
    bg.remove(2);
    bg.remove(9);
    bg.remove(9);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;

    bg.insert(20);
    bg.remove(3);
    bg.remove(5);
    bg.remove(7);
    bg.remove(11);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;
    bg.remove(20);
    debug(, bg.l, bg.suml, bg.r, bg.sumr);
    cout << bg.cost() << endl;
}

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