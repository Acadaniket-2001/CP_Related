#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long ll;                 typedef vector<int> vi;
typedef unsigned long long ull;       typedef vector<ll> vll;
typedef long double ld;               typedef vector<vll> vvl;
typedef priority_queue<ll> pqmax;     typedef priority_queue<ll,vector<ll>,greater<ll>> pqmin; 
#define p_q priority_queue
#define PI 3.141592653589793238462
#define P 1000000007
#define P1 998244353
#define EPS 1e-9
#define f(i,a,b) for(long long i=a;i<=b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mkp make_pair
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define gg cout << -1 << "\n"
#define ln cout << "\n"
#define re return
template <class T>istream& operator >>(istream &is, vector<T> &v) { for(auto &i : v)    is >> i; return is; };
//---- VG_Debugger ---- //
#ifndef ONLINE_JUDGE
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define debvmat(vec) cerr << #vec << " :\n"; for (auto r: vec) { for (auto c: r) cerr << c << " "; cerr << endl; }  // Mine added.
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
//--------Mine Added (Inspiration: VG)--------- //
template <class T>ostream& operator <<(ostream& os, queue<T> p){ os << "[ "; while(!p.empty()) { os << p.front() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream& os, stack<T> p){ vector<T> v; while (!p.empty()) { v.push_back(p.top()); p.pop(); } reverse(all(v)); os << v; return os; }
template <class T>ostream& operator <<(ostream& os, priority_queue<T> p){ os << "[ "; while (!p.empty()) { os << p.top() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream& os, priority_queue<T,vector<T>, greater<T>> p){ os << "[ "; while (!p.empty()) { os << p.top() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream& os, const deque<T> &p){os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#define debvmat(vec){}
#endif
//--------------------- //
long long POW(long long a,long long b){return (long long)(pow(a,b)+0.5);}
long long gcd(long long a,long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return (a*b)/__gcd(a,b);}
long long Ceil(long long a,long long b){return (a+b-1)/b;}
long long Sqrt(long long x){ long long y=sqrt(x)+5;while(y*y>x)y--;return y;}
/*---------------------------------> Greedy / Constructive <---------------------------------
.                                        D T D P G B
⭐ D -> Decode the operation     ⭐ D -> Dimensional Setup         ⭐ G -> Greedy / Sorting
⭐ T -> Think in reverse         ⭐ P -> Prefix or Suffix ideas    ⭐ B -> Bit Manipulation
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------Finding all the divisors---------------------------------

// Finding all the divisors of all numbers belonging to [1 - n] in O(nlog(n))
// There is one already 1 way of O(n.root(n))...think?
// but O(n.root(n)) > O(nlog(n))

vector<int> divi[100005];
void pre_compute() {
    for(int i = 1; i <= 100000; i++) {
        for(int j = i; j <= 100000; j += i) {
            divi[j].pb(i);
        }
    }
}

//  T.C.
//  (100000 / 1) + (100000 / 2) + (100000 / 3) + (100000 / 4) + ... + (100000 / 100000)
//  100000 (1/1 + 1/2 + 1/3 + 1/4 + ... + 1/100000) = O(100000.log(100000))

void solve() {
    f(i, 1, 50) {               // change (50)
        dbg(divi[i]);           // just run cph
    }
}

int main()
{
    fastio();
    pre_compute();
    int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}

---------------------------------------------------------------------------------------------*/

// O(sqrt(N))
// N <= 10^12 or <= 10^13
bool is_prime(ll x) {
    if(x < 2)   return 0;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0)  return 0;
    }
    return 1;
}

// Finding all Factors/divisors of a number
// N <= 10^12 or <= 10^13
// # Divisors(N) = O(sqrt(N))
vector<ll> Divisors(ll n) {
    vector<ll> ans;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ans.pb(i);
            if(i != n/i)  ans.pb(n/i);
        }  
    }
    sort(all(ans));
    return ans;
}

// Prime_Factorising a number
// N <= 10^12 or <= 10^13
// O(sqrt(N))
vector<pair<ll, ll>> prime_factor(ll n) {
    vector<pair<ll, ll>> ans;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ll cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            ans.pb({i, cnt});
        }
    }
    if(n > 1)  ans.pb({n, 1});
    return ans;
}

// Finding all primes in [1, N]: 
// O(N.log(log(N)))
// N <= 10^7
vector<ll> sieve(ll a, ll b) {
    vector<bool> is_prime(1000006, 1);
    is_prime[0] = is_prime[1] = 0;
    
    for(int i = 2; i * i <= 1000005; i++) {
        if(is_prime[i]) {
            for(ll j = 1LL*i*i; j <= 1000005; j += i)
                is_prime[j] = 0;
        }
    }

    vll ans;
    f(i, a, b) {
        if(is_prime[i]) ans.pb(i);
    }
    return ans;
}

// Finding primes in [a, b]:
// 0 <= a <= b <= 10^12 and (b - a) <= 10^6
vll seg_sieve(ll a, ll b) {

    vll primes = sieve(1, Sqrt(b));
    
    vll is_prime(b - a + 10, 1);
    if(a == 1)  is_prime[0] = 0;

    for(auto x : primes) {
        ll mul = Ceil(a, x) * x;
        for(ll i = mul; i <= b; i += x) {    // looping through all multiples of x b/w [a, b]
            if(i != x)  is_prime[i - a] = 0; // if(...) is needed to handle cases: 1 <= a <= sqrt(b) <= b
        }
    }

    vll ans;
    f(i, a, b) {
        if(is_prime[i - a]) ans.pb(i);
    }
    return ans;
}

// Fast Prime_Factorising a number
// To answer (Q <= 10^6) queries of (N <= 10^6)
// pre_computation -> O(N.log(log(N) ) )
// O(Q.log(N))
// ⚠️ Must call SPF() in main() before using fastPrimeFact()..
const int N = 1e6 + 10;
vector<ll> spf(N);
void SPF() {
    f(i, 2, N - 1)    spf[i] = i;

    f(i, 2, N - 1) {
        if(spf[i] == i) {
            for(ll j = 2*i; j < N; j += i)
                if(spf[j] == j) spf[j] = i;
        }
    }
}
vector<ll> fastPrimeFact(ll n) {
    vll ans;
    while(n != 1) {
        ans.pb(spf[n]);
        n /= spf[n];
    }
    return ans;
}

// Sieve Applications: (N < =10^7)
// Sieve can be used to find the properties of a number in range[1 - N],
// provided the properties has some relation with factorisation and divisors

// N = (p1^ɑ1) * (p2^ɑ2) * (p3^ɑ3) * ... * (pn^ɑn)

// ⭐ Number of divisors of a number.
//         #(divisors) = (ɑ1 + 1) * (ɑ2 + 1) * (ɑ3 + 1) * ... * (ɑn + 1)

// ⭐ Sum of divisors of a number.
//  sum = (1 + p1 + p1^2 +...+ p1^ɑ1) . (1 + p2 + p2^2 +...+ p2^ɑ2)...(1 + pn + pn^2 +...+ pn^ɑn)
//  Use GP sum formula to compute the sum

// ⭐ Calculating phi(x):
// phi((x) = Count of numbers a in [1, x] such that gcd(a, x) = 1
//                 i.e. count of coprime pairs
// ⚠️ Must call Phi() in main() before using phi[i].
vll phi(1e6 + 5);
void Phi() {
    // sieving out primes
    vector<bool> is_prime(1e6 + 6, 1);
    is_prime[0] = is_prime[1] = 0;
    for(ll i = 2; i * i <= 1e6; i++) {
        if(is_prime[i]) {
            for(ll j = 1LL*i*i; j <= 1e6; j += i)
                is_prime[j] = 0;
        }
    }
    // initialising phi[]
    f(i, 1, 1e6)    phi[i] = i;
    // Computing phi[]
    f(i, 2, 1e6) {
        if(is_prime[i]) {
            for(ll j = i; j <= 1e6; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main()
{
    fastio();
    pr(seg_sieve(1, 20));
    return 0;
}
