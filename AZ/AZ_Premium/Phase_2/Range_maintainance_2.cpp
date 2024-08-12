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

// If vector<..> v(n) is sorted in inc. order
// Notes:  For mn(e) : e >= x   -->   LB(x); 
// Notes:  For mn(e) : e > x    -->   UB(x); 
// Notes:  For mx(e) : e < x    -->   LB(x)--; 
// Notes:  For mx(e) : e <= x   -->   UB(x)--; 

// Notes:  For #(e) : e >= x    -->   n - LB(x);
// Notes:  For #(e) : e > x     -->   n - UB(x);
// Notes:  For #(e) : e < x     -->   LB(x);
// Notes:  For #(e) : e <= x    -->   UB(x);

struct range_maintainance {
    set<pair<int, int>> st;

    void fill_range(int l, int r) {
        auto it = st.upper_bound({l, 1e9});
        if(it != st.end()) {
            it--;
            l = min(l, it -> ff);
        }
        
        it = st.upper_bound({r, 0});
        if(it != st.begin()) {
            it--;
            if(it -> ff >= l) {
                r = max(r, it -> ss);
            }
        }

        while(1) {
            it = st.lower_bound({l, 0});
            if(it != st.end() and it -> ff <= r)
                st.erase(it);
        }
        st.insert({l, r});
    }

    void clear_range(int l, int r) {

    }

    bool check_point(int x) {
        auto it = st.upper_bound({x, 1e9}); // try{x, 0}
        if(it != st.begin()) {
            it--;
            if(it -> ss >= x)   return 1;
            else    return 0;
        }
        else return 0;
    }

    bool check_range_any(int l, int r) {
        auto it = st.lower_bound({l, 0});           // try {l, 1e9}   -> should give error
        if(it != st.end()) {
            if(it -> ff <= r)
                return 1;
        }
        return check_point(l);
    }

    bool check_range_all(int l, int r) {
        auto it = st.upper_bound({l, 1e9});         // {l, 0} -> fails
        if(it != st.begin()) {
            it--;
            if(it -> ss >= r)   return 1;   
            else    return 0; 
        }
        else return 0;
    }

    // int count(int x) { // Range Maintainance Idea 1 }

    void printer() {
        cout << "Current Status: ";
        for(auto e: st) {
            cout << "(" << e.ff << ", " << e.ss << "), ";
        }
        cout << endl;
    }
};


int main() {

    int q; cin >> q;
    struct range_maintainance bg;

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int l, r; cin >> l >> r;
            bg.fill_range(l, r);
        }
        else if(t == 2) {
            int l, r; cin >> l >> r;
            bg.clear_range(l, r);
        }
        else if(t == 3) {
            int x; cin >> x;
            bg.check_point(x);
        }
        else if(t == 4) {
            int l, r; cin >> l >> r;
            bg.check_range_any(l, r);
        }
        else {
            int l, r; cin >> l >> r;
            bg.check_range_all(l, r);
        }
        bg.printer();
    }
    return 0;
}