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

/*
Given a tree of n nodes, your task is to find a centroid, i.e., a node such that when it is appointed
the root of the tree, each subtree has at most 
⌊n/2⌋ nodes.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.


Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes 
a and b.

Output Format
Print one integer: a centroid node. If there are several possibilities, print the smallest one.

Constraints
1≤n≤2⋅10^5
1≤a,b≤n
*/

void pre() {

}

int n;
vector<vector<int>> g;
vector<int> subtreeSz;
int G;
 
void dfs(int node, int parent) {
    subtreeSz[node] = 1;
    for(auto v: g[node]) {
        if(v != parent) {
            dfs(v, node);
            subtreeSz[node] += subtreeSz[v];
        }
    }
}

// // level        -> node
// // choice       -> either node in G or some subtree[node] is centroid
// // check n move -> if all subtree[i] of root is <= n/2 
// //                      root is cnetroid
// //                 else 
// //                      move to  i: subtree[i] > n/2
// void find_centroid(int node, int parent) {
//     bool ok = 1;
//     int next = 0;
//     for(auto v: g[node]) {
//         if(v != parent) {
//             ok &= (subtreeSz[v] <= n/2);
//             if(subtreeSz[v] > n/2)  next = v;
//         }
//     }
//     // node is G
//     if(ok) {
//         G = node;
//         return;
//     }
//     // node is not G
//     find_centroid(next, node);
// }

// method 2
void find_centroid(int node, int parent) {
    bool ok = 1;
    for(auto v: g[node]) {
        if(v != parent) {
            if(subtreeSz[v] > n/2) {
                ok = 0;
                find_centroid(v, node);
            }
        }
    }
    if(ok)  G = node;
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    subtreeSz.resize(n + 1);

    f(i, 1, n - 1) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0);

    find_centroid(1, 0);
    
    dfs(G, 0);                         // ⭐ to root the tree at G and calc. the new subtreeSz[i]

    // find smallest possible G
    int mn = G;
    for(auto poss_G: g[G]) {
        // pr(poss_G, mn);
        if(n - subtreeSz[poss_G] <= n/2) {
            mn = min(mn, poss_G);
        }
    }    

    cout << mn;
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
    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}

/*
🤩⭐⭐⭐ AZ Editorial: Elegent solution


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n;
vector<vector<int>> adj;
vector<int> cnt, centroids;
void dfs(int v, int p) {
    cnt[v] = 1;
    bool is_centroid = true;
    for (auto x : adj[v]) {
        if (p == x)continue;
        dfs(x, v);
        cnt[v] += cnt[x];
        if(cnt[x]>n/2)is_centroid=false;
    }
    // the nodes in the subtree are all now computed.
	if(n-cnt[v]>n/2) is_centroid = false;
    if(is_centroid) centroids.push_back(v);
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    cnt.assign(n + 1, 0);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout<< *min_element(centroids.begin(),centroids.end())<<endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}

*/