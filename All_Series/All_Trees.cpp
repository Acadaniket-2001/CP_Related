#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

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
#define llINT_MAX 1e18
#define iINT_MAX 1e9
#define endl "\n"
#define pb push_back
#define ppb pop_back
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

/*------------------------------------------------------------------------------------

⭐ No need to keep visited[ ] in trees problems -> Why? ->  no chances of getting into
    infinite loop (see copy), just maintain the parent of current node while traversal

-------------------------------------------------------------------------------------*/

/*-------------------------⭐Diameter of a tree (DFS Approach)⭐------------------------------

// Imp. Interview Question
// Very General tree problem Code format

// BFS approach also possible
// Follow up: try finding the number of diameters in a tree (For Hint: see copy)

vector<vector<int>> g;
vector<int> parent;
vector<int> dist;

void dfs(int nn, int pp, int dd) {   // nn->node , pp->parent , dd->distance from start node
    dist[nn] = dd;
    parent[nn] = pp;
    // Add
    for(auto v : g[nn]) {
        if(v != pp)                  // prevents infinte loop
            dfs(v, nn, dd + 1);
        // Add
    }
    // Add
}

void solve() {
    int n; cin >> n;
    g.resize(n + 1);   
    parent.resize(n + 1);
    dist.resize(n + 1);

    f(i, 1, n - 1) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0, 0);     // finds the dist. of all nodes from node:1 (random) with hypo. parent 0
    int mx1 = 1;          
    f(i, 2, n) {
        if(dist[mx1] < dist[i]) mx1 = i;
    }

    dfs(mx1, 0, 0);   // finds the dist. of all nodes from node:mx1 with hypo. parent 0
    int mx2 = 1;
    f(i, 2, n) {
        if(dist[mx2] < dist[i]) mx2 = i;
    }


    // Tracing paths(diameter) in a tree       -> General Concept
    vector<int> path;
    int temp = mx2;
    while(parent[temp] != 0) {
        path.pb(temp);
        temp = parent[temp];
    }
    path.pb(temp);
    
    cout << "|D|: " << sz(path) - 1 << endl;
    for(auto x : path)  cout << x << " ";
    cout << endl;
    
    // Centres
    if(sz(path) & 1)
        int Centre = path[path.size() / 2];
    else {
        int Centre1 = path[path.size() / 2];
        int Centre2 = path[(path.size() - 1) / 2];
    }
}

signed main() {
    
    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}

------------------------------------------------------------------------------------*/

/*-------------------------⭐Centroid of a tree (DFS Approach)⭐------------------------------

vector<vector<int>> g;
vector<int> centroid;
vector<int> subTreeSZ;
int n;

// dfs() recursive faith : 
//          dfs() calculates the subTree size
//          of node(nn) with parent(pp) and stores in subTreeSZ[nn] 
//          and it also tells whether isCentroid(nn)?

void dfs(int nn, int pp) {
    subTreeSZ[nn] = 1;
    for(auto v : g[nn]) {
        if( v!= pp) {
            dfs(v, nn);
            subTreeSZ[nn] += subTreeSZ[v];
        }
    }

    bool isCentroid = 1;
    for(auto v : g[nn]) {
        if(v != pp) {
            if(2*subTreeSZ[v] > n) isCentroid = 0;
        }
    }
    if( 2*(n - subTreeSZ[nn]) > n ) isCentroid = 0;

    if(isCentroid)  centroid.pb(nn);
}

void solve() {
    cin >> n;
    g.resize(n + 1);
    subTreeSZ.resize(n + 1);

    f(i, 1, n - 1) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0);     // 1 -> any random node

    for(auto x : centroid)
        cout << x << " ";
    cout << endl;
}

signed main() {
    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}

//i/p:
// 8
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 7 8

// o/p: 3 1

------------------------------------------------------------------------------------*/

/*-------------------------------⭐find: ∑ ∑ dist(a, b)⭐-------------------------------------------

// Problem: Given a weighted tree of N nodes find: ∑ ∑ dist(a, b) 
//          for all a,b belonging to set N.

vector<vector<pair<int, int>>> g;
vector<int> subTreeSZ;
ll ans = 0;
int n;

void dfs(int nn, int pp, int wt) {
    subTreeSZ[nn] = 1;
    for(auto v : g[nn]) {
        if(v.ff != pp) {
            dfs(v.ff, nn, v.ss);
            subTreeSZ[nn] += subTreeSZ[v.ff];
        }
    }
    ans += 2LL*(subTreeSZ[nn] * (n - subTreeSZ[nn]) ) * wt;   // 2LL* becoz: a ---> b and a <--- b
                                                                  // same edge contributes 2 times
}

void solve() {
    cin >> n;
    g.resize(n + 1);
    subTreeSZ.resize(n + 1);

    f(i, 1, n - 1) {
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    dfs(1, 0, 0);  // 3rd argument is the weight of incoming egde on node 1, since 1 is taken as root here so wt = 0;                               

    cout << ans << endl;
}

signed main() {
    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}

// i/p:
// 3
// 1 2
// 1 3

//o/p: 8

// i/p:
// 3
// 1 2 3
// 1 3 2

//o/p: 20

------------------------------------------------------------------------------------*/

void solve() {
    cout << "⭐" << endl;
}

signed main() {
    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}