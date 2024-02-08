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
#define MOD 1000000007
#define MOD1 998244353
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
#define yes cout << "Yes" << "\n"
#define no cout << "No" << "\n"
#define re return
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

struct Dsu {
    // n-> #nodes, set_size-> #components
    // rank[i]: stores the size of each component with i as root
    // parent[i]: stores the parent of each node
    int n, set_size, *parent, *rank;
    Dsu() {}
    Dsu(int a) {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 1; i <= n; ++i) { parent[i] = i, rank[i] = 1; }
    }
    
    //Don't directly use parent[node] to get parent of node instead use find(i), as it may lead to some error
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
    void reset() { set_size = n; for(int i = 1; i <= n; ++i) { parent[i] = i; rank[i] = 1; } }
    int size() { return set_size; }
    void print() { for(int i = 1; i <= n; ++i) { cout << i << " -> " << parent[i] << endl; } }
};

// /*--------------------------------------MST_Algorithms-------------------------------------------

vector<pair<int, pair<int, int>>> g[100100];
class comp {
    public: 
        bool operator() (pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2) {
            return  p1.ss.ss > p2.ss.ss;
        }
};
void mst_prims() {
    int n, m; cin >> n >> m;
    Dsu dsu(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;
    
    int start; cin >> start;
    f(i, 0, m - 1) {
        int a, b, c; cin >> a >> b >> c;
        g[a].pb({a, {b, c}});
        g[b].pb({b, {a, c}});
        if(a == start) {
            pq.push({a, {b, c}});
        }
    } 

    int min_cost = 0;
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int u = x.ff, v = x.ss.ff;

        if(dsu.find(u) == dsu.find(v))  continue;

        min_cost += x.ss.ss;
        dsu.merge(u ,v);
        for(auto xx : g[v]) {
            pq.push(xx);
        }
    }
    
    cout << min_cost << endl;
}

void mst_kruskal() {
    int n, m; cin >> n >> m;
    Dsu dsu(n);

    vector<pair<int, pair<int, int>>> edgelist;
    vector<pair<int, int>> g[100100];       // {dest, wt}
    f(i, 0, m - 1) {
        int a, b, c; cin >> a >> b >> c;
        edgelist.pb({c, {a, b}});
    }

    sort(all(edgelist));

    int min_cost = 0;
    int cnt = 0;
    for(auto v : edgelist) {
        int a = v.ss.ff, b = v.ss.ss;   
        int wt = v.ff;

        if(dsu.find(a) == dsu.find(b))  continue;
        min_cost += wt;
        g[a].pb({b, wt});
        g[b].pb({a, wt});

        dsu.merge(a, b);
        cnt++;
    }

    if(cnt != n - 1) {
        cout << "No Solution\n" << endl;
        return;
    }

    cout<< min_cost << endl;
    // g[] has the AdjList of MST
}

int main()
{
    mst_kruskal();       // T.C. = O(E.logE + (E + V).Auckerman(V)) = O(E.logE)
    // mst_prims();      // prim's algo is not so imp for CP  // ⚠️run prims code only after giving start
    return 0;
}

//i/p:
// 6 7
// 1 3 1
// 5 6 1
// 1 2 2
// 3 6 2
// 2 3 3
// 4 5 4
// 3 4 10

//o/p: 10

// ----------------------------------More Problems on MST:---------------------------------------- 
// 1. Maximum spanning tree
//         M1: Modify mst_kruskal()
//         M2: Reverse the signs of weights of edges -> find min_cost -> ans = -min_cost;
// 2. Goods delivery to all plants problem
//         M1: Add a pseudo start node connected to all plants with wt
//             equal to plant opening cost; ans = mst_cost of modified graph.

// ------------------------------------------------------------------------------------------------*/

/*--------------------------------------∑ ∑ d(i ,j): (i != j)----------------------------------------------------------

// Problem : Given a tree find double summation d(i, j) for all i, j and i != j
//           where d() gives the min cost edge in the path from i to j

// Hint: Contribution Technique of edges

void solve() {
    int n; cin >> n;
    Dsu dsu(n);
    vector<pair<int, pair<int, int>>> edgelist;
    f(i, 1, n - 1) {
        int a, b, c; cin >> a >> b >> c;
        edgelist.pb({-c, {a, b}});
    } 

    sort(all(edgelist));

    int ans = 0;
    for(auto x : edgelist) {
        int u = x.ss.ff, v = x.ss.ss;
        int uroot = dsu.find(u), vroot = dsu.find(v);
        
        ans += (-x.ff) * (dsu.rank[uroot] * dsu.rank[vroot]);
        dsu.merge(u, v);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}

//i/p:
// 5
// 5 4 1
// 4 3 3
// 3 1 2
// 3 2 4

//o/p: 20 = 4(1 * 1) + 3(1 * 2) + 2(1 * 3) + 1(1 * 4)

// ------------------------------------------------------------------------------------------------*/