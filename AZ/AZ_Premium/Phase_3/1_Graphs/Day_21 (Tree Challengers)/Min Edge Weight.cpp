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

// method 2 - no template 💀💀💀

int n;
vector<pair<int, pair<int, int>>> edgeList;        // {wt, {u, v}}  

vector<int> par, ranks;
int find(int x) {
    if(par[x] == x)     return x;
    else return par[x] = find(par[x]);
}
void merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);

    if(rootx != rooty) {
        if(ranks[rootx] <= ranks[rooty]) {
            ranks[rooty] += ranks[rootx];
            par[rootx] = rooty;
        }
        else {
            ranks[rootx] += ranks[rooty];
            par[rooty] = rootx;
        }
    }
}

void solve()
{
    cin >> n;
    ranks.assign(n + 1, 1);
    par.assign(n + 1, 0);

    f(i, 1, n)  par[i] = i;

    f(i, 1, n - 1) {
        int a, b, w;    cin >> a >> b >> w;
        edgeList.pb({-w, {a, b}});
    }

    sort(all(edgeList));
    // pr(edgeList);

    ll ans = 0;
    for(auto e: edgeList) {
        int wt = -e.ff, u = e.ss.ff, v = e.ss.ss;
        int rootx = find(u);
        int rooty = find(v);
        ans += wt * (1LL * ranks[rootx] * ranks[rooty]);
        merge(u, v);
    }

    cout << ans << endl;
    edgeList.clear();
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


/*method 1 using template

// n-> #nodes, set_size-> #components
// rank[i]: stores the size of each component with i as root
// parent[i]: stores the parent of each node
// ⚠️ Don't directly use parent[node] to get parent of node instead use find(i), as it may lead to some error. 

struct Dsu {
    int n, set_size, *parent, *rank;
    Dsu() {}
    Dsu(int a) {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 1; i <= n; ++i) { parent[i] = i, rank[i] = 1; }
    }
    int find(int x) {
        if(parent[x] == x)  return x;
        else return parent[x] = find(parent[x]);       // path compression
    }
    void merge(int x ,int y) {
        int xroot = find(x), yroot = find(y);
        if(xroot != yroot) {
            if(rank[xroot] >= rank[yroot]) {           // rank compression
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }
    void reset() {
        set_size = n; for(int i = 1; i <= n; ++i) parent[i] = i, rank[i] = 1;
    }
    int size() { return set_size; }
    void print() {for(int i = 1; i <= n; ++i) cout << i << " -> " << parent[i] << endl;}
};


int n;
vector<pair<int, pair<int, int>>> edgeList;        // {wt, {u, v}}  

void solve()
{
    cin >> n;
    f(i, 1, n - 1) {
        int a, b, w;    cin >> a >> b >> w;
        edgeList.pb({-w, {a, b}});
    }

    sort(all(edgeList));

    Dsu dsu(n);
    ll ans = 0;

    for(auto e:edgeList) {
        int wt = -e.ff, u = e.ss.ff, v = e.ss.ss;
        int rootx = dsu.find(u);
        int rooty = dsu.find(v);

        ans += wt * (1LL * dsu.rank[rootx] * dsu.rank[rooty]);

        dsu.merge(u, v);
    }

    cout << ans << endl;
    edgeList.clear();
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
*/

