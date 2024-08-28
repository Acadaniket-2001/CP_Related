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

// Problem: For each index print the ranges which have the same AND value along with the corresponding AND value.
// Formally: In v[ ] for each idx i: find the all [L, R] such that AND(a[i] & a[i+1]...a[x]) for all x in [L, R] is same

// i/p:
// 5
// 7 1 3 6 2

//o/p foramat: 
// Starting at Index i
// L1    R1   AND(a[i] & a[i+1] & a[i+2] & ... & a[x] : x in [L1, R1])
// L2    R2   AND(a[i] & a[i+1] & a[i+2] & ... & a[x] : x in [L2, R2])
//  ...
//--------------------------

// o/p:
// Starting at Index 4
// 4 4 2

// Starting at Index 3
// 3 3 6
// 4 4 2

// Starting at Index 2
// 2 2 3
// 3 4 2

// Starting at Index 1
// 1 2 1
// 3 4 0

// Starting at Index 0
// 0 0 7
// 1 2 1
// 3 4 0


void solve()
{
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    map<int, int> prev_ends;    //  {x, y} --> We have '& value' x till index y
    for(int i = n - 1; i >= 0; i--) {
        map<int, int> new_ends;
        for(auto e: prev_ends) {
            // new_ends[e.ff & v[i]] = max({new_ends[e.ff & v[i]], prev_ends[e.ff & v[i]], e.second});  // why not this ???
            new_ends[e.ff & v[i]] = max(new_ends[e.ff & v[i]], e.second);
        }
        // new_ends[v[i]] = max({new_ends[v[i]], prev_ends[v[i]], i});
        new_ends[v[i]] = max(new_ends[v[i]], i);
        prev_ends = new_ends;



        // cout << "Index: " << i << endl;
        // for(auto e: new_ends) {
        //     cout << e.ff << " " << e.ss << endl;
        // }
        // cout << endl;



        vector<pair<int, int>> ranges(all(new_ends));
        reverse(all(ranges));
        cout << "Starting at Index " << i << endl;
        f(ed, 0, sz(ranges) - 1) {
            if(ed == 0) {
                // [i...ranges[ed].ss] -> ranges[ed].ff
                cout << i << " " << ranges[ed].ss << " " << ranges[ed].ff << endl;
            }         
            else {
                // [ranges[ed - 1].ss + 1....ranges.[ed].ss] -> ranges[ed].ff
                cout << ranges[ed - 1].ss + 1 << " " << ranges[ed].ss << " " << ranges[ed].ff << endl;
            }
        }
        ln;   
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}


// Further: Same trick applies for __Gcd() of subarray as there are only log(n) possible gcd() in an arrays... may be]