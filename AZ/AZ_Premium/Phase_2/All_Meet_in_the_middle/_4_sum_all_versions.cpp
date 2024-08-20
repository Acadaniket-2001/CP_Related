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

// Note: a, b, c, d :  are indices in v[ ]

void solve_version_1() {
    int n, t; cin >> n >> t;
    vector<int> v(n);  cin >> v;

    map<int, int> pos;
    f(a, 0, n - 1) {
        f(b, 0, n - 1) {
            pos[v[a] + v[b]] = 1;
        }
    }

    f(c, 0, n - 1) {
        f(d, 0, n - 1) {
            if(pos[t - v[c] - v[d]]) {
                cout << 1 << endl;
                re;
            }
        }
    }
    cout << 0 << endl;
}

void solve_version_2()
{
    int n, t; cin >> n >> t;
    vector<int> v(n); cin >> v;
    map<int, int> mp;


    // //.. my_way
    // mp[v[n - 1] + v[n - 2]]++;
    // int b = n - 3;
    // while(1) {                                // O(N^2.log(N^2) = O(N^2.logN)

    //     f(a, 0, b - 1) {                      // O(N^2.log(n^2))       over entire while loop
    //         if(mp.find(t - v[a] - v[b]) != mp.end()) {
    //             cout << 1 << endl;
    //             re;
    //         }
    //     }

    //     int c = b;
    //     b--;
    //     if(b == 0)  break;

    //     f(d, c + 1, n - 1) {                  // O(n^2)        over entire while loop
    //         mp[v[c] + v[d]] = 1;
    //     }
    // }
    // cout << 0 << endl;

    
    //..AZ_way (I modified for(b...))
    for(int b = n - 1; b >= 0; b--) {
        f(a, 0, b - 1) {
            if(mp[t - v[a] - v[b]]) {
                cout << 1 << endl; 
                re; 
            }
        }
        int c = b;
        f(d, c + 1, n - 1) {
            mp[v[c] + v[d]] = 1;
        }
    }
    cout << 0 << endl;
}

// my_way   --->    AZ_way
void solve_version_3() {
    int n, t; cin >> n >> t;;
    vector<int> v(n); cin >> v;

    map<int, pair<int, int>> mp;         // mp< t-v[a]-v[b] , pair<c, d> > = mp< v[c]+v[d] , pair<c, d>


    // int b = n - 2;
    // while(1) {             
    //     f(a, 0, b - 1) {
    //         auto it = mp.find(t - v[a] - v[b]);
    //         if(it != mp.end()) {
    //             cout << a << " " << b << " " << (it->ss).ff << " " << (it->ss).ss << endl;
    //             re;
    //         }
    //     }

    //     int c = b;
    //     b--;
    //     if(b == 0)  break;
        
    //     f(d, c + 1, n - 1)  mp[v[c] + v[d]] = {c, d};
    // }
    // cout << -1 << endl;


    for(int b = n - 2; b > 0; b--) {             
        f(a, 0, b - 1) {
            auto it = mp.find(t - v[a] - v[b]);
            if(it != mp.end()) {
                pair<int, int> ans = it->ss ;
                cout << a << " " << b << " " << ans.ff << " " << ans.ss << endl;
                re;
            }
        }

        int c = b;

        f(d, c + 1, n - 1)  mp[v[c] + v[d]] = {c, d};
    }
    cout << -1 << endl;
}

void solve_version_4() {
    int n, t; cin >> n >> t;
    vector<int> v(n); cin >> v;

    ll ans = 0;
    map<int, int> mp;      // mp< t-v[a]-v[b] , freq(t-v[a]-v[b]) >

    rf(b, n - 1, 0) {
        f(a, 0, b - 1) {
            ans += mp[t - v[a] - v[b]];
        }
        int c = b;
        f(d, c + 1, n - 1)  mp[v[c] + v[d]]++;
    }

    cout << ans << endl;
}

int main()
{
    fastio();
    
    int _t; cin >> _t; while(_t--) {
        solve_version_1();             // a, b, c, d : can be same, chk(): v[a]+v[b]+v[c]+v[d] == target
        // solve_version_2();             // a, b, c, d : are distinct, chk(): v[a]+v[b]+v[c]+v[d] == target
        // solve_version_3();             // a, b, c, d : are distinct, find[a,b,c,d] : v[a]+v[b]+v[c]+v[d] == target
        // solve_version_4();             // a, b, c, d : are distinct, cnt[a,b,c,d] : v[a]+v[b]+v[c]+v[d] == target
    }
    return 0;
}