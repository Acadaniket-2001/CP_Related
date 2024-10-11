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
/*---------------------------------------------------------------------------------------------------------------------------*/

/*
Problem: 
    ⭐ Solved here,
    Given an array, divide it into K partitions💡 such that ∑((min of each partition)) is min. Find the summation.          
    --> Can also be done by greedy appraoch: ans = ∑(top K smallest elements od arr[]) 

    Eg: 
    5 3
    1 3 2 5 4
    o/p: 6 (= 1 + 3 + 2, i.e. 1| 3| 2 5 4 )

Other Versions
    Given an array, divide it into K partitions such that ∑((max of each partition)) is min. Find the summation.          
    --> Can't be done by greedy.
*/

#define INF 1e9

int n, K;
int arr[1001];

int dp[1001][101];
int rec(int i, int x) {                                 
    // pruning
    if(x < 0)   return INF;

    // base case
    if(i == -1) {                                       // ⭐ same base case for most partitioning problems of Form2
        if(x == 0)  return 0;
        else return INF;
    }

    // cache check
    if(dp[i][x] != -1)
        return dp[i][x];

    //  Xition 
    int ans = INF;
    int run_min = arr[i];
    for(int j = i - 1; j >= -1; j--) {                  // ⭐ maintaining running min. to save cost of Xtiton, j = -1 for the case when K = 1 so, we need to entire array as a partition. 
        ans = min(ans, rec(j, x - 1) + run_min);
        run_min = min(run_min, arr[j]);
    }

    // save and return 
    return dp[i][x] = ans;
}

void solve()
{
    cin >> n >> K;
    f(i, 0, n - 1)  cin >> arr[i];

    memset(dp, -1, sizeof dp);                          // assuming arr[i] >= 0

    cout << rec(n - 1, K);                              // rec(level, no. of partitions to be done)
}

int main()
{
    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("io/Error.txt", "w", stderr);
    //     freopen("io/Input.txt", "r", stdin);
    //     freopen("io/Output.txt", "w", stdout);
    // #endif

    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}