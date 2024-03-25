#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i,a,b) for(long long i=a;i<=b;i++)
#define rrep(i,a,b) for(long long i=a;i>=b;i--)
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
// to get custom MOD(m), modify line no. 8
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_expo(ll a, ll n) { ll res = 1; while(n) { if(n % 2)   res = mod_mul(res, a), n--; else a  = mod_mul(a, a), n /= 2; } return res; }
ll mod_inv(ll a) { return mod_expo(a, MOD - 2); }   //MOD must be prime ; (a, MOD) -> coprime
ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)); }

//-------------------------------------------------------------------------------------------------

/*------------------------------Merge_Sort------------------------------*/

// /*------------------------------------------------------------------------

// Given an array.
// Find the number of subarrays with (max_element - min_element) <= K

// AlgoZenith Way => (easiest pattern to code)
// must dry run for revision

int main() {

    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int _t; cin >> _t; while(_t--) {
        ll n, k; cin >> n >> k;
        vll v(n);
        for(auto &x : v)    cin >> x;

        multiset<ll> mst;
        ll ans = 0;

        ll head = -1, tail = 0;
        while(tail < n) {
            while(head + 1 < n and ( (max(v[head + 1], (mst.size() ? *mst.rbegin() : (ll)(-1e18))) - min(v[head + 1], (mst.size() ? *mst.begin() : (ll)(1e18))) <= k) )) {
                mst.insert(v[head + 1]);
                debug(mst);
                head++;
            }
            ans += (head - tail + 1);
            if(tail <= head) {
                mst.erase(mst.find(v[tail]));
                tail++;
            }
            else {
                tail++;
                head = tail - 1;
            }
        }
        cout << ans << endl;
    }

    return 0 ;
}

// ------------------------------------------------------------------------*/

/*------------------------------------------------------------------------

// Given 2 arrays a[ ] of size n and b[ ] of size m.
// find the number of pairs such that A[i] < b[j].
// Both arrays have unique elements.

void solve()
{
    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    for(auto &x : a)    cin >> x;
    for(auto &x : b)    cin >> x;

    ll cnt = 0;
    for(int i = 0, j = 0; j < m; j++) {
        while(i < n and a[i] < b[j])   i++;
        cnt += i;
    }
    cout << cnt;

    ll x; cin >> x;
    cout << find_pair_with_sum(a, x) << endl;
}

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

//Testcase
// 7 6
// 1 2 3 5 7 10 12
// 1 2 4 6 6 9

------------------------------------------------------------------------*/

/*------------------------------------------------------------------------

// Given a sorted array with 'n' unique elements.
// Find how pairs exists with sum = x;

ll find_pair_with_sum(const vector<ll>& a, int x) {
    ll cnt = 0;
    int i = 0, j = sz(a) - 1;
    while(i < j) {
        if(a[i] + a[j] < x) i++;
        else if(a[i] + a[j] > x) j--;
        else    cnt++, i++, j--;
    }

    return cnt;
}

void solve()
{
    ll n; cin >> n;
    vll a(n);
    for(auto &x : a)    cin >> x;

    ll x; cin >> x;
    cout << find_pair_with_sum(a, x) << endl;
}

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

------------------------------------------------------------------------*/

/*------------------------------------------------------------------------

// Given 2 sorted arrays a[] and b[] sorted in non decreasing order.
// Count the number of pairs such that a[i] == b[j]

void method_1() {            // using only maps

    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    for(auto &x : a)    cin >> x;
    for(auto &x : b)    cin >> x;

    map<int, int> cnta, cntb;
    for(auto x: a)   cnta[x]++;
    for(auto x: b)   cntb[x]++;

    ll ans = 0;
    for(auto e: cnta) {
        ans += e.ss * (cntb[e.ff]);
    }
    cout << ans << "\n";

}

void method_2()            // using map<> and 2-pointers
{
    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    for(auto &x : a)    cin >> x;
    for(auto &x : b)    cin >> x;

    map<int, int> cnta, cntb;
    for(auto x: a)   cnta[x]++;
    for(auto x: b)   cntb[x]++;

    ll ans = 0;
    int i = 0, j = 0;        // i -> a[] and j -> b[]
    while(i < n and j < m) {
        
        if(a[i] < b[j]) i++;
        
        else if(a[i] > b[j]) j++;
        
        else {
            ans += cnta[a[i]] * cntb[b[j]];
            i += cnta[a[i]];
            j += cntb[b[j]];
        }
    }

    cout << ans << "\n";

}


void method_3() {            // pure two-pointers

    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    for(auto &x : a)    cin >> x;
    for(auto &x : b)    cin >> x;

    int i = 0, j = 0;
    int cnt = 0;
    while(i < n and j < m) {

        if(a[i] < b[j]) i++;
        
        else if(a[i] > b[j]) j++;

        else {
            int t1 = i;
            while(t1 < n and a[t1] == a[i]) t1++;
            int cnta = t1 - i;
            i = t1;
            
            int t2 = j;
            while(t2 < m and b[t2] == b[j]) t2++;
            int cntb = t2 - j;
            j = t2;

            cnt += cnta * cntb;
        }
    }

    cout << cnt << "\n";

}

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    cin >> t;
    while(t--) {
        method_1();
        // method_2();
        // method_3();
    }
    return 0;
}

------------------------------------------------------------------------*/

// /*------------------------------------------------------------------------

// Given an array of a[] of length 'n'.
// Print the maximum sum subarray.
// Kadane's algorithm

void solve2()
{
    ll n; cin >> n;
    vll v(n); cin >> v;

    // variation 2 : subarray can be empty
    ll mx = 0, curr = 0, hi = -1, lo = 0, ansl, ansr;
    f(i, 0, n - 1) {
        curr += v[i];
        curr = max(0LL, curr);
        if(curr == 0)   lo = i + 1 ,hi = lo - 1;
        else hi = i;

        mx = max(mx, curr);
        if(mx == curr)  ansl = lo, ansr = hi;
    }

    cout << mx << " " << ansl << " " << ansr << endl;
    f(i, ansl, ansr)    cout << v[i] << " \n"[i == ansr];
}

void solve1() {                         // train method -> pepcod..      

    ll n; cin >> n;
    vll v(n);
    for(auto &x : v)    cin >> x;
    

    ll sum = 0, mx = 0;                 // sum = INT_MIN; if subarray can't be empty
    ll l = 0, r = 0, ansl = 0, ansr = 0;
    for(int i = 0; i < n; i++) {
        
        if(sum + v[i] >= v[i]) {         // same as -> if(sum >= 0)
            sum += v[i];
            r = i;
        }
        else {
            sum = v[i];
            l = r = i;
        }
        
        if(sum > mx) {
            mx = sum;
            ansl = l, ansr = r;
        }
    }
    cout << mx << endl;
    cout << ansl << " " << ansr << "\n";
}

// Testcase
// 1
// 19
// 4 3 -2 6 7 -10 -10 4 5 9 -3 4 7 -18 2 9 3 -2 11

// ans -> 31, [7, 18]


int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    cin >> t;
    while(t--) {
        // solve();
        // solve1();
        solve2();
    }
    return 0;
}

// ------------------------------------------------------------------------*/

/*------------------------------------------------------------------------

// Given a array with 'n' non-negative elements.
// Find how many subarrays exists with sum >= x;

void solve()
{
    ll n; cin >> n;
    vll v(n);
    for(auto &x : v)    cin >> x;

    ll x; cin >> x;
    ll sum = 0, cnt = 0; 
    for(int i = 0, j = 0; i < n; i++) {

        while(j < n and sum < x) {
            sum += v[j];
            j++;
        }

        if(sum >= x) {
            cnt += n - j + 1;
            sum -= v[i];
        }
        
    }

    cout << cnt << endl;
    
}

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

------------------------------------------------------------------------*/

/*------------------------------------------------------------------------

// Try :- (Use set/multiset)
// Given a array with 'n' elements.
// Find how many subarrays exists with sum >= x;
// here -10^9 <= a[i] <= 10^9.

void solve() {                      
    ll n; cin >> n;
    vll v(n + 1);
    rep(i, 1, n)    cin >> v[i];
    
    ll x; cin >> x;
    vll pre(n + 1, 0);

    pre[1] = v[1];
    rep(i, 2, n) {
        pre[i] = pre[i - 1] + v[i];
    }

    debug(pre)

    ll cnt = 0;
    pbmultiset<ll> mst;
    mst.insert(0);
    rep(i, 1, n) {
        cnt += mst.order_of_key(pre[i] - x + 1);
        mst.insert(pre[i]);
    }
    cout << cnt << endl;
}

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}

------------------------------------------------------------------------*/
