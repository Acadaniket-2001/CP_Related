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
/*-------------------> Current Level <----------------------
2. Think all possibilities
3. Think greedy
4. Think sortings
5. Think constructive algorithms
1. ⭐ Think brute force
6. ⭐ Think implementation
7. ⭐ Think math
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Given [L, R]: find the OR(a[i]), AND(a[i]) for all L <= i <= R
void solve()
{
    ll n; cin >> n;
    vector<int> v(n); cin >> v;

    vector<vector<int>> bits(n, vector<int> (31, 0));

    f(i, 0, n - 1) {
        f(j, 0, 30) {
            if(i == 0)  bits[i][j] = ((v[i] & (1 << j)) != 0);
            else bits[i][j] = bits[i - 1][j] + ((v[i] & (1 << j)) != 0);
        }
    }
    dbg(bits);

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        int ans1 = 0, ans2 = 0;
        f(j, 0, 30) {
            int cnt = bits[r][j] - (l == 0 ? 0 : bits[l - 1][j]);
            if(cnt) ans1 |= (1 << j);
            if(cnt == r - l + 1) ans2 |= (1 << j);
        }
        cout << ans1 << " "  << ans2 << endl;
    }
}

// count pairs if (i, j): i < j and a[i] AND a[j] >= a[i] XOR a[j]
void solve1() {
    ll n; cin >> n;
    vector<int> v(n); cin >> v;

    auto find_msb = [&](int a) {
        f(i, 30, 0) {
            if(a & (1 << i))    return i;
        }
    };

    //m1
    map<int, int> mp;
    int ans = 0;
    f(i, 0, n - 1) {
        int set_bit = find_msb(v[i]);
        ans += mp[set_bit];
        mp[set_bit]++;
    }
    cout << ans << endl;

    //m2
    map<int, int> mp1;
    f(i, 0, n - 1) {
        mp1[find_msb(v[i])]++;
    }

    int cnt = 0;
    for(auto e : mp1) {
        cnt += (e.ss)*(e.ss - 1) / 2;
    }
    cout << cnt << endl;
}


// find ∑ ∑ (a[i] XOR a[j]), ∑ ∑ (a[i] AND a[j]), ∑ ∑ (a[i] OR a[j]) : i < j
// Hint : Think bit by bit (for Kth bit)
void solve2() {
    int n; cin >> n;
    vll v(n); cin >> v;

    // map<ll, ll> cnt0, cnt1;
    // f(i, 0, n - 1) {
    //     f(j, 0, 30) {
    //         int bit = ((v[i] & (1 << j)) != 0);
    //         if(bit) cnt1[j]++;
    //         else cnt0[j]++;
    //     }
    // }
    // ll ans = 0;
    // f(k, 0, 30) {
    //     ans += (cnt0[k] * cnt1[k]) * (1LL << k);
    // }
    // cout << ans << endl;

    // Optimised
    ll xorr = 0, andd = 0, orr = 0;
    f(bit, 0, 30) {
        int cntsetbit = 0;
        f(i, 0, n - 1) {
            if(v[i] & (1 << bit)) cntsetbit++;
        }
        int notset = n - cntsetbit;

        andd +=  ((cntsetbit) * (cntsetbit - 1) / 2) * (1 << bit);

        int totalPairs_OR = n*(n - 1)/2 - (notset*(notset - 1)/2);       // total_pairs - #pairs(0, 0) 
        orr +=  (totalPairs_OR) * (1 << bit);

        xorr += (cntsetbit * notset) * (1 << bit);
    }
    cout << "AND : " << andd; ln;
    cout << "OR : " << orr; ln;
    cout << "XOR : " << xorr; ln;
}


// bitmasking -> to iterate over all subsets
void solve3() {
    int n; cin >> n;
    vll v(n); cin >> v;

    map<ll, ll> sum;      // mp<mask, sum>
    ll last = (1 << n) - 1;

    // m1
    // f(mask, 0, last) {
    //     int currSum = 0;
    //     f(bit, 0, n - 1) {
    //         if(mask & (1 << bit))   currSum += v[bit];
    //     }
    //     sum[mask] = currSum;
    // }
    // for(auto e: sum) cout << e.ff << " -> " << e.ss << endl; 

    
    // m2
    // 10010 -> 1st and 4th elements are present
    // 10000 ->  (< 10010) => computed before (10010) => 10010 = sum[10000] + v[1st_elem.] 
    // 00010 ->  (< 10010) => computed before (10010) => 10010 = sum[00010] + v[4th_elem.] 
    f(mask, 0, last) {
        f(bit, 0, 30) {
            if(mask & (1 << bit)) {
                int remMask = mask - (1 << bit);
                sum[mask] = sum[remMask] + v[bit];
                break;                      // -> se  example above for break;
            }
        }
    }
    for(auto e: sum) cout << e.ff << " -> " << e.ss << endl; 
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
    // solve();
    // solve1();
    // solve2();
    solve3();
    return 0;
}