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

// to get custom modulo m, pass new modulo as argument
ll madd(ll a, ll b, ll M = P) {
    return (a%M + b%M) % M;
}
ll msub(ll a, ll b, ll M = P) {
    return (((a%M - b%M) % M) + M) % M;
}
ll mmul(ll a, ll b, ll M = P) {
    return ((a % M) * (b % M)) % M;
}
ll mpow(ll base, ll exp, ll M = P) {
    ll res = 1;
    while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % M;
    }
    exp >>= 1;
    base = (base * base) % M;
    }
    return res;
}
ll minv(ll base, ll M = P) { // M must be prime ; (base, M) -> coprime
    return mpow(base, M - 2);
}
ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
}

/*-------------------> Greedy / Constructive <----------------------
                        D T D P G B
⭐ D -> Decode
⭐ T -> Think in reverse
⭐ D -> Dimensional Setup
⭐ P -> Prefix or Suffix ideas
⭐ G -> Greedy / Sorting
⭐ B -> Bit Manipulation
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void rec(int n) {
    if(n == 0) {
        cout << 0;
        re;
    }
    rec(n >> 1);
    cout << n % 2;
}

int main()
{

    // // printing binary rep. of no.
    // int n; cin >> n;
    // rf(i, 63, 0) {
    //     if(n & (1LL << i))  cout << 1;
    //     else cout << 0;
    // }
    // rec(n);


    // // all nos. in array occur 3 times except 1 which occurs only once , find the no.
    // ll n; cin >> n;
    // vll v(n); cin >> v;
    // ll ans = 0;
    // f(bit, 0, 30) {
    //     int cntSet = 0;
    //     f(i, 0, n - 1)
    //         cntSet += ((v[i] & (1LL << bit))!= 0);
    //     if(cntSet % 3)
    //         ans |= (1 << bit);
    // }
    // cout << ans << endl;


    // // all nos. in array occur even times except 1 which occurs  odd times , find the no. with odd freq.
    // ll n; cin >> n;
    // vll v(n);   cin >> v;
    // ll ans = 0;
    // f(j, 0, 30) {
    //     int cntSet = 0;
    //     f(i, 0, n - 1)
    //         cntSet += ((v[i] & (1LL << j))!= 0);
    //     if(cntSet % 2)
    //         ans |= (1 << j);
    // }
    // cout << ans << endl;
    // //or
    // ll ans1 = 0;
    // f(i, 0, n - 1)  ans1 = ans1 ^ v[i];
    // cout << ans1 << endl;


    // // all nos. in array occur 2 times except 2 elements which occurs only 1 time , find the 2 nos. with freq. = 1.
    // ll n; cin >> n;
    // vll v(n);   cin >> v;
    // int xorr = 0;
    // f(i, 0, n - 1)  xorr ^= v[i];
    // // finding any set bit in xorr .... ??? -> becoz this bit is different in the two req. nos.  => here finding LSB
    // int bit = xorr & (~(xorr - 1));        // xorr = 10110100  => bit = 100
    // int x = 0, y = 0;       // x -> for ith bit - 1, y for 0
    // f(i, 0, n - 1) {
    //     if(v[i] & (bit)) x ^= v[i];
    //     else y ^= v[i];
    // }    
    // cout << x << " " << y << endl;  
    

    // // find XOR of all nos. from [1, n]: =============================================================
    // auto xorr = [](int n) {
    //     int s = n % 4;
    //     switch(s) {
    //         case 0: return n; 
    //         case 1: return 1; 
    //         case 2: return n + 1; 
    //         case 3: return 0; 
    //     }
    // };
    // // int n; cin >> n;
    // // cout << xorr(n);

    // // find XOR[L, R]: ===============================================================================
    // int l, r; cin >> l >> r;
    // int ans = xorr(r) ^ (l == 0 ? 0 : xorr(l - 1));
    // cout << ans << endl;

    // // 1 no. is missing from the list of nos. from 1 to n.... find the missing no.: ==================
    // int n; cin >> n;
    // vii v(n); cin >> v;
    // int xorr_arr = 0;
    // f(i, 0, n - 1)  xorr_arr ^= v[i];
    // cout << xorr(n) ^ xorr_arr;




    // // given n; find the number of i : (0 <= i <= n and n + 1 = n ^ i)
    // int n;  cin >> n;
    // int temp = n;
    // int cnt0 = 0;
    // while(temp) {
    //     if((temp & 1) == 0) cnt0++;
    //     temp >>= 1;
    // }
    // cout << (1LL << cnt0) << endl;




    // // find the XOR of all the possible subarrays of an arr[ ]     --> contribution technique
    // int n; cin >> n;
    // vii v(n); cin >> v;
    // int ans = 0;
    // f(i, 0, n - 1) {
    //     if(1LL * (i + 1) * (n - i) % 2)     ans ^= v[i];
    // }
    // cout << ans << endl;



    // // Suppose f(X,Y) = number of positions in binary representation where bits differ. 
    // // Given an array of integers, find the sum of f(a[i],a[j]) for every possible i and j in range 1 to n. 
    // // Find answer modulo 10^9+7.
    // ll n; cin >> n;
    // vll v(n); cin >> v;
    // ll ans = 0;
    // f(j, 0, 30) {
    //     ll cntSet = 0;
    //     f(i, 0, n - 1) {
    //         if(v[i] & (1 << j))     cntSet = (cntSet + 1) % P;
    //     }
    //     ll contribution_of_ith_bit = cntSet * ((n % P - cntSet) % P);
    //     ans = (ans + contribution_of_ith_bit) % P;
    // }
    // ans = (ans * 2) % P;                  //   since i != j and not i < j
    // ans = (ans%P + P) % P;                // to remove the problem of -ve value 
    // cout << ans;



    // // find the min XOR of pair of elements of arr[ ]   --> for intutitve proof of soln. see notes 
    // int n; cin >> n;
    // vii v(n); cin >> v;
    // int mn_xor = INT_MAX;
    // sort(all(v));
    // f(i, 1, n - 1) {
    //     mn_xor = min(mn_xor, v[i] ^ v[i - 1]);
    // }
    // cout << mn_xor;



    // // find the total no. of set bits in all nos. from⭐[0, n]
    // ll n; cin >> n;
    // n++;                     // cnt of numbers = n + 1   ---->   [0, 9] = 9-0+1 = 10
    // ll ans = 0;
    // f(i, 0, 3) {
    //     ll cur = n / (1LL << (i + 1));
    //     cur *= (1LL << i);
    //     cur += max((n % (1LL << (i + 1))) - (1LL << i), 0LL);
    //     debug(cur, cur);
    //     ans += cur;
    // }
    // cout << ans;

    
    return 0;
}