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

void pre() {

}

#define INF 1e9

int n, m;
string x, y;

vector<vector<int>> dp;
int rec(int i, int j) {
    // pruning

    // base case
    // if(i == n and j == m)
    //     return 0;
    // else if (i == n)
    //     return (m - j);                               // adding +y[j...m-1]
    // else if (j == m)
    //     return (n - i);                               // adding -x[i...n-1]

	// base case (OR)
	if(i == n or j == m)
		return (n - i) + (m - j);                       // ❤️❤️❤️ nice trick to handle multiple possibilities : (i<n, j=m) (i=n, j<m) (i=n, j=m)

    // cache chk
    if(dp[i][j] != -1)
        return dp[i][j];

    // Xition
    int ans = INF;
    ans = min(ans, 1 + rec(i + 1, j));                // adding -x[i]
    ans = min(ans, 1 + rec(i, j + 1));                // adding +y[j]
    if(x[i] == y[j])
        ans = min(ans, 1 + rec(i + 1, j + 1));        // adding x[i]
        
    // save and return
    return dp[i][j] = ans;
}

void generate(int i, int j) {
    if(i == n and j == m)
        return;
    else if(i == n) {
        f(k, j, m - 1)  cout << '+' << y[j] << " ";
        re;
    }
    else if(j == m) {
        f(k, i, n - 1)  cout << '-' << x[i] << " ";
        re;
    }

	// // M1
    // int ans = INF;
    // ans = min(ans, 1 + rec(i + 1, j));                // adding -x[i]
    // ans = min(ans, 1 + rec(i, j + 1));                // adding +y[j]
    // if(x[i] == y[j])
    //     ans = min(ans, 1 + rec(i + 1, j + 1));        // adding x[i]

    // if(ans == 1 + rec(i, j + 1)) {
    //     cout << '+' << y[j] << " ";
    //     generate(i, j + 1);
    // }
    // else if(ans == 1 + rec(i + 1, j)) {
    //     cout << '-' << x[i] << " ";
    //     generate(i + 1, j);
    // }
    // else {
    //     cout << x[i] << " ";
    //     generate(i + 1, j + 1);
    // }

	// M2
	if(rec(i, j) == 1 + rec(i, j + 1)) {
        cout << '+' << y[j] << " ";
        generate(i, j + 1);
	}
	else if (rec(i, j) == 1 + rec(i + 1, j)) {
        cout << '-' << x[i] << " ";
        generate(i + 1, j);
	}
	else {
        cout << x[i] << " ";
        generate(i + 1, j + 1);
	}
}

// 💡 See Code in copy for printing using back pointers...

void solve()
{
    cin >> x >> y;
    n = x.size(), m = y.size();

    dp.assign(n, vector<int>(m, -1));

    cout << rec(0, 0)<< endl;

    generate(0, 0);
    ln;
}

int main()
{
    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("io/Error.txt", "w", stderr);
    //     freopen("io/Input.txt", "r", stdin);
    //     freopen("io/Output.txt", "w", stdout);
    // #endif

    pre();
    int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}
