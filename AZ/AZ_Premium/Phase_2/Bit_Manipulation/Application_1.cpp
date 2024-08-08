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

// Application_1 : Counting various bits ppty using contribution ideas 

// finding kth 1 in oo binary string: s = 0 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 .......
// version 1: Q <= 10; k <= 10^5
// version 2: Q <= 10^5; k <= 10^5
// version 3: Q <= 10^5; k <= 10^9 or above...


// Version 1 and 2
// string getbinstr(int n) {
//     string ans = "";
//     if(n == 0)  return "0";
//     while(n) {
//         ans += (n % 2 ? '1' : '0');
//         n >>= 1;
//     }
//     reverse(all(ans));
//     return ans;
// }

// int main()
// {
//     // pre_computation
//     string s = ""; 
//     int n = 0;
//     int cnt1 = 0;
//     while(cnt1 <= 100) {         // cnt1 <= max(k), say 100
//         string to_add = getbinstr(n);
//         for(auto e: to_add)     cnt1 += (e == '1');
//         s += to_add;
//         n++;
//     }
//     vector<int> pos1;
//     f(i, 0, sz(s) - 1) {
//         if(s[i] == '1') pos1.pb(i); 
//     }

//     // Query processing
//     int q; cin >> q;
//     while(q--) {
//         int k; cin >> k;
//         cout << pos1[k - 1] << endl;
//     }
   
//     return 0;
// }


// version 3: Q <= 10^5; k <= 10^9
string getbinstr(int n) {
    string ans = "";
    if(n == 0)  return "0";
    while(n) {
        ans += (n % 2 ? '1' : '0');
        n >>= 1;
    }
    reverse(all(ans));
    return ans;
}


ll getpos(ll num, ll k) {
    // ll msb = 63 - __builtin_clzll(num);
    // ll i = msb;
    // ll cnt = 0;
    // while(cnt < k) {
    //     if(num & (1 << i))  cnt++;
    //     if(cnt == k) {
    //         return msb - i + 1;
    //     }
    //     i--;
    // }

    string s = getbinstr(num);
    ll cnt1 = 0;
    f(i, 0, sz(s) - 1) {
        if(s[i] == '1')    cnt1++;
        if(cnt1 == k) {
            return i + 1;
        }
    }
}

ll find_one_till_num(ll n) {
    ll N = n + 1;                          // N - Range of [0, n]
    ll ans = 0;
    f(i, 0, 25) {                          // kmx = 10^5 ~ 10^6 = 2^20
        ll contribution_ith_bit = N / (1LL << (i + 1));
        contribution_ith_bit *= (1LL << i);
        contribution_ith_bit += max(N % (1LL << (i + 1)) - (1LL << i), 0LL);
        ans += contribution_ith_bit;
    }
    return ans;
}

ll find_num_with_kth_one(int k) {
    ll lo = 0, hi = k, ans = -1;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if(find_one_till_num(mid) >= k) {
            ans = mid, hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

ll cnt_bits_till(ll x) {
    // ll bits_req = (ll)__lg(x) + 1;
    // ll cnt = 0;
    // f(i, 0, bits_req - 1) {
    //     cnt += max(0LL, x + 1 - (1 << i));        // cnt += contribution of ith bit
    // }
    // return cnt + 1;

    ll cnt = 0, num = 1, len = 1;
    while(num <= x) {
        ll same_len_till = num * 2 - 1;
        if(same_len_till <= x) {
            cnt += len*(same_len_till - num + 1);
            num = same_len_till + 1;
            len++;
        }
        else {
            cnt += len * (x - num + 1);
            break;
        }
    }
    return cnt + 1;
}

int main() {

    ll q; cin >> q;
    
    while(q--) {
        ll k; cin >> k;
        ll num = find_num_with_kth_one(k);
        ll one_before_num = find_one_till_num(num - 1);
        ll req_1_in_num = k - one_before_num;
        ll pos_of_req_1_in_num = getpos(num, req_1_in_num);
        ll ans = cnt_bits_till(num - 1) + pos_of_req_1_in_num - 1;
        // cout << ans << endl;
        cout << cnt_bits_till(4) << endl;    
    }

    return 0;
}