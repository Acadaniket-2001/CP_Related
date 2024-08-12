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

// Problem: Given a set of intervals and an int X, find the number of intervals which contains X.

// ⭐ This idea works only because the two subsets are disjoint...
// Otherwise it would have lead to overcounting / undercounting while processing starts and ends separately.

// #include <bits/stdc++.h>
// using namespace std;

// int count_ranges( vector<int> &starts, vector<int>& ends, int Y) {
//     // Find the number of ranges that start after Y
//     int start_count = starts.size() - (upper_bound(starts.begin(), starts.end(), Y) - starts.begin());

//     // Find the number of ranges that ends before Y
//     int end_count = (upper_bound(ends.begin(), ends.end(), Y) - ends.begin());

//     // The number of ranges passing through Y is the overlap
//     return (starts.size() - (start_count + end_count));
// }

// int main() {
//     vector<pair<int, int>> ranges = {{1, 5}, {3, 7}, {6, 9}, {8, 11}};
//     vector<int> queries = {3, 6, 8};


//     vector<int> starts, ends;
//     for (const auto& range : ranges) {
//         starts.push_back(range.first);
//         ends.push_back(range.second);
//     }
//     sort(starts.begin(), starts.end());
//     sort(ends.begin(), ends.end());

//     for (int Y : queries) {
//         cout << count_ranges(starts, ends, Y) << endl;
//     }
// }



int main() {
    int n; cin >> n;
    vii l(n), r(n);
    f(i, 0, n - 1){
        cin >> l[i] >> r[i];
    }

    sort(all(l));
    sort(all(r));
    
    int q; cin >> q;
    while(q--) {
        int y;  cin >> y;
        int cnt1 = n - (upper_bound(all(l), y) - l.begin());
        int cnt2 = lower_bound(all(r), y) - r.begin();
        int ans = n - cnt1 - cnt2;
        cout << ans << endl;
    }

    return 0;
} 

// i/p:
// 4
// 1 5
// 3 7
// 6 9
// 8 11
// 3
// 3 6 8

// o/p: 
// 2
// 2
// 2
