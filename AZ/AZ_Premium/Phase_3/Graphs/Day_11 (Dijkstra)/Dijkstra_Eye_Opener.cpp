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

// ⭐ Always beware whether to use INF = 1e9 / 1e18; --> as the distance of a node can be >1e9 in some cases.

/*
⚠️⚠️⚠️⚠️⚠️ Dijkstra() doesn't work even work in -ve  wts G(V, E) not only in -ve wts cycles.
Proof: Try running this directed G with -ve wts.
i/p:
10 12
1 2 40
1 3 30
1 4 20
1 5 10
2 6 -32 
3 6 -20
4 6 -8
5 6 4
6 7 -6
6 8 -6
6 9 -6
6 10 -6
*/

/*
Mistake: not using vis[ ] in Dijk. --->  TLE. 
i/p:
10 12
1 2 2 
1 3 2
1 4 2
1 5 2
2 6 1 
3 6 2
4 6 3
5 6 4
6 7 2
6 8 2
6 9 2
6 10 2

Without using vis[ ] line [172-173], the code is logically correct, but will give TLE in onion graph case (see above i/p..) 
o/p:
poped : (0, 1), pq : [ (-2, 5) (-2, 4) (-2, 3) (-2, 2) ], dis : [ INF 0 2 2 2 2 INF INF INF INF INF ]
poped : (-2, 5), pq : [ (-2, 4) (-2, 3) (-2, 2) (-6, 6) ], dis : [ INF 0 2 2 2 2 6 INF INF INF INF ]
poped : (-2, 4), pq : [ (-2, 3) (-2, 2) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 5 INF INF INF INF ]
poped : (-2, 3), pq : [ (-2, 2) (-4, 6) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 4 INF INF INF INF ]
poped : (-2, 2), pq : [ (-3, 6) (-4, 6) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 INF INF INF INF ]
poped : (-3, 6), pq : [ (-4, 6) (-5, 10) (-5, 9) (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-4, 6), pq : [ (-5, 10) (-5, 9) (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 10), pq : [ (-5, 9) (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 9), pq : [ (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 8), pq : [ (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 7), pq : [ (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 6), pq : [ (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-6, 6), pq : [ ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]



With using vis[ ] line [172-173], the code will not give TLE in onion graph case (see above i/p..) 
o/p;
poped : (0, 1), pq : [ (-2, 5) (-2, 4) (-2, 3) (-2, 2) ], dis : [ INF 0 2 2 2 2 INF INF INF INF INF ]
poped : (-2, 5), pq : [ (-2, 4) (-2, 3) (-2, 2) (-6, 6) ], dis : [ INF 0 2 2 2 2 6 INF INF INF INF ]
poped : (-2, 4), pq : [ (-2, 3) (-2, 2) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 5 INF INF INF INF ]
poped : (-2, 3), pq : [ (-2, 2) (-4, 6) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 4 INF INF INF INF ]
poped : (-2, 2), pq : [ (-3, 6) (-4, 6) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 INF INF INF INF ]
poped : (-3, 6), pq : [ (-4, 6) (-5, 10) (-5, 9) (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 10), pq : [ (-5, 9) (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 9), pq : [ (-5, 8) (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 8), pq : [ (-5, 7) (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
poped : (-5, 7), pq : [ (-5, 6) (-6, 6) ], dis : [ INF 0 2 2 2 2 3 5 5 5 5 ]
*/

/*
Mistake: marking visited to node(i) when push in priority queue. (See notes AZ Phase_3:Day_9)
*/

// just use pq in Dijkstras() in place of q in BFS() and add a vis[ ] filter. ---> (always follow this code)
# define int ll
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dis, vis;

void dijkstra(int st) {
    dis.assign(n + 1, 1e18);
    vis.assign(n + 1, 0);


    priority_queue<pair<int, int>> pq;     // {-cost to reach node, node}
    dis[st] = 0;
    pq.push({-0, st});

    while(!pq.empty()) {
        pair<int, int> node = pq.top(); pq.pop();

        if(vis[node.ss] == 1)   continue;
        vis[node.ss] = 1;

        for(auto v: g[node.ss]) {         // going [node] -> [neigh]
            int neigh = v.ff;
            int wt = v.ss;
            if(dis[neigh] > dis[node.ss] + wt) {
                dis[neigh] = dis[node.ss] + wt;
                pq.push({-dis[neigh], neigh});
            }
        }
        // pr(node, pq, dis);
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);

    f(i, 1, m) {
        int a, b, w;    cin >> a >> b >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }

    dijkstra(1);

    cout << "dist[]: " << dis; 
}

signed main()
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