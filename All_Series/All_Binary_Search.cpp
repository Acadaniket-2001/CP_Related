#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
/* find_by_order(k)  returns iterator to kth element starting from 0;
 * order_of_key(k) returns count of elements strictly smaller than k;*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f(i,a,b) for(long long i=a;i<=b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define llINT_MAX 1e18
#define iINT_MAX 1e9
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mkp make_pair
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
void _print(ld t) {cerr << t;}
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
//---------------------------------------------------------------------------------------------------------------------------

// Must see diagram(CP_Resources Samsung-notes) before reading this
// To find NOE, see STL TRICKS section in Learnings.txt (at Desktop)

int main()
{
    vector<int> v{1, 2, 2, 3, 3, 3, 4, 5, 6, 10};
    int _t; cin >> _t; while(_t--) {

        int x; cin >> x;

        // elements < x                 => Think which parts are to be at the same seg.
        auto it = lower_bound(all(v), x);     
        // #(elements < x)              
        cout << it - v.begin() << endl;
        
        // elements >= x
        auto it1 = lower_bound(all(v), x);
        // #(elements >= x)
        cout << v.end() - it1 << endl;
        

        
        // elements > x                 => Think which parts are to be at the same seg.
        auto it2 = upper_bound(all(v), x);     
        // #(elements > x)
        cout << v.end() - it2 << endl;
        
        // elements <= x
        auto it3 = upper_bound(all(v), x);
        // #(elements <= x)
        cout << it3 - v.begin() << endl;

        //-----------------------------------------------------------------------------
        
        cout << "Freq" << "(" << x << "): "; 
        cout << upper_bound(all(v), x) - lower_bound(all(v), x) << endl;

        cout << "\n";
    }

    return 0;
}
