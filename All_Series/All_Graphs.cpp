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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define p_q priority_queue
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

/*------------------------------------------------------------------------------------

Steps to solve a graph problem:
    1.  Understand the question by manually calculating the answer 
        using abstractions of algo(s)
    
    2.  Replace the abstract algo(s) with some known graph algorithm.

⭐ General Construct (DFS) : clear -> create -> component

⭐ bfs(node) -> Gives the length of shortest path from given node to all other nodes.

⭐ Maze is a Graph such that adjacent(reachable) elements of maze have an edge b/w them.

⭐ In multi_source type probelms, mostly problem is solved by creating a pseudo src node.

-------------------------------------------------------------------------------------*/

/*-----------------------------Counting_Connected_Components (DFS)--------------------------

// This is a general idea used in many problems

// Problem : Given a graph with N nodes, M edges. Find the number of edges that can be
//           added to it in order to decrease the number of components in it.

vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int comp) {
    vis[node] = comp;
    for(auto v : g[node]) {
        if(!vis[v]) {
            dfs(v, comp);
        }
    }
}

void solve() {

    int n, m; cin >> n >> m;
    g.clear();                 // important if testcases are present
    g.resize(n + 1);           // using 1 based nodes
    vis.assign(n + 1, 0);

    f(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int comp_cnt = 0;
    f(i, 1, n) {        // this part is necessary if graph has multiple components
        if(!vis[i]) {   // if whole G(V, E) is connected, anot needed -> dfs(start, comp_cnt); 
            comp_cnt++;
            dfs(i, comp_cnt);
        }
    }

    vector<int> arr(comp_cnt + 1, 0);
    for(auto x : vis) {
        arr[x]++;
    }

    ll sum = 0, ans = 0;
    for(int i = sz(arr) - 1; i >= 1; i--) {
        ans += sum * arr[i];
        sum += arr[i];
    }

    cout << ans << endl;
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    int _t; cin >> _t; while(_t--)
    solve();
}

------------------------------------------------------------------------------------------*/

/*-----------------------------Checking_Bipartite (DFS)-------------------------------------

// Problem : Given a class of N students and pair of friends, find out whether we can
//           split the class such that no 2 friends of same pair are in the same part.

// i/p: 
// 1
// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 1

// Flipping numbers
//     say using 5 and 6
//     color = 5;
//     color = color ^ 5 ^ 6          //flip color b/w 5 and 6 
//     color = sum(5, 6) - color      //flip color b/w 5 and 6 

vector<vector<int>>g;
vector<int> vis;
bool is_bip = true;

void dfs(int nn, int color) {
    vis[nn] = color;
    for(auto v : g[nn]) {
        if(!vis[v]) {
            dfs(v, 1^2^color);
        }
        else {
            if(vis[v] == vis[nn])   is_bip = false;
        }
    } 
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    int _t; cin >> _t; 
    while(_t--) {

        int n, m; cin >> n >> m;

        g.clear();
        g.resize(n + 1);
        vis.assign(n + 1, 0);

        f(i, 1, m) {
            int a, b; cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }

        is_bip = 1;
        int color = 1;         // using color 1 and 2
        f(i, 1, n) {
            if(!vis[i]) {
                dfs(i, color);
            }
        }

        cout << (is_bip ? "Yes" : "No") << endl;
    }

}

-------------------------------------------------------------------------------------*/

/*-----------------------------Single_source_shortest_path (BFS)----------------------------

// Problem : Given a maze with walls(#) and a single Start and End postitons, 
//           find the shortest path b/w Start and End.

// i/p:
// 6 6
// #....#
// ####.#
// ......
// .#....
// .####.
// ......
// 0 1
// 5 0

// Variation_1 : If single monster is present and can choose to move and stay.
//    Soln : do dfs(S) -> dist(S, E) < dist(M, E) => Yes, We can flee...else No

// Variation_2 : If multiple Exits and single M is present.
//    Soln : A complex Game theory problem.

// Variation_3 : If multiple monster are present and can choose to move and stay independently.
//    Soln : do dfs(E) -> if there exist some M : dist(E, M) < dist(E, S) => We can't flee

// Variation_4 : If multiple Start and Exits are present and no monsters.
//    Soln : Multi Source bfs (Pseudo Node Concept) => See Copy


vector<string> maze;

// to store shortest distance
// also serves as vis[ ], here            // Concept
int n, m;
vector<vector<int>> dist;

// to store parent of each node 
vector<vector<pair<int, int>>> par;

// movement vectors                     ->  General Concept
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y) {               // General Concept
    return (x >= 0 and x < n and y >= 0 and y < m and maze[x][y] != '#');
}

void bfs(pair<int, int> st) {
    queue<pair<int, int>> q;
    q.push(st);
    while(!q.empty()) {
        auto pos = q.front();
        q.pop();
        
        f(i, 0, 3) {
            if(check(pos.ff + dx[i], pos.ss + dy[i])) {
                if(dist[pos.ff + dx[i]][pos.ss + dy[i] ] > dist[pos.ff][pos.ss] + 1) {
                    dist[pos.ff + dx[i]][pos.ss + dy[i] ] = dist[pos.ff][pos.ss] + 1;
                    par[pos.ff + dx[i]][pos.ss + dy[i] ] = {pos.ff, pos.ss};
                    q.push({pos.ff + dx[i], pos.ss + dy[i] } );
                }
            }
        }
    }
}

void print_path(pair<int, int> en) {     // General Idea to print paths
    if(dist[en.ff][en.ss] == 0) {
        cout << en.ff << " " << en.ss << endl; return;
    }

    print_path(par[en.ff][en.ss]);
    cout << en.ff << " " << en.ss << endl;
}

void solve() {
    cin >> n >> m;
    maze.resize(n);       //maze.assign(n,"");
    f(i, 0, n - 1) {
        cin >> maze[i];
    }

    pair<int, int> st, en;
    cin >> st.ff >> st.ss >> en.ff >> en.ss;
    
    dist = vector<vector<int>>(n, vector<int>(m, 1e9));
    par = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, {0, 0}));
    
    dist[st.ff][st.ss] = 0;
    bfs(st);
    cout << "Shortest distance : " << dist[en.ff][en.ss] << endl;
    print_path(en);
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Topological_Sort (DFS)---------------------------------------

// See copy for why this algorithm works ?
// Can't detect cycles like Kahn's

vector<int> g[100100];
int vis[100100];

vector<int> topo;
void dfs(int nn) {
    vis[nn] = 1;
    for(auto v : g[nn]) {
        if(!vis[v])
            dfs(v);
    }
    topo.pb(nn);    // Only change in dfs()
}

void solve() {
    int n, m; cin >> n >> m;
    f(i, 1, m) {
        int a, b; cin >> a >> b;           // Considering (a) -> (b) i.e. a depends on b
        g[b].pb(a);                        // Beware!!!,  pushing (b) -> (a) intentionally
    }    

    f(i, 1, n) {
        if(!vis[i]) dfs(i);
    }

    reverse(all(topo));
    
    cout << "Topological Sort : ";
    for(auto x : topo)    cout << x << " ";
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

// i/p:
// 6 6
// 2 1
// 3 1
// 4 2
// 4 3
// 5 3
// 6 4

// Topological Sort : 1 3 5 2 4 6

-------------------------------------------------------------------------------------*/

/*-----------------------------Topological_Sort (BFS) -> (Kahn's algorithm)-----------------

// Usecase of Kahn algorithm : To detect cycles in G(V, E)
//            Do Kahn's algor. on G(V, E),
//            And those 'V' which does not apprear in topo[] are part of some cycle in G. 

int n, m;
vector<int> g[100100];
int indegree[100100];
vector<int> topo;

void kahn() {
    queue<int> q;
    f(i, 1, n) {
        if(indegree[i] == 0)
            q.push(i);
    }  

    while(!q.empty()) {
        auto v = q.front();
        q.pop();

        topo.pb(v);

        for(auto x : g[v]) {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }        
    }
}

void solve() {
    cin >> n >> m;
    f(i, 1, m) {
        int a, b; cin >> a >> b;     // a -> b
        g[b].pb(a);                  // pushing b -> a, intentionally
        indegree[a]++;
    }

    kahn();    // bfs();
    
    // Topo Array
    for(auto x : topo)
        cout << x << " ";
     
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

// i/p:
// 6 6
// 2 1
// 3 1
// 4 2
// 4 3
// 5 3
// 6 4
// o/p : 1 2 3 4 5 6

// i/p:
// 5 5
// 1 2
// 2 3
// 3 4
// 4 1
// 3 5
// o/p : 5

// ------------------------------------------------------------------------------------------*/

// Application of Topological ordering : 
/*-----------------------------Lexicographically_smallest_topological_ordering--------------

// Hint: Kahn's Algorithm + Min_Priority_queue

vector<int> g[100100];
int indegree[100100];
vector<int> topo;
int n, m;

void bfs() {
    priority_queue<int> q;
    f(i, 1, n) {
        if(!indegree[i]) {
            q.push(-i);
        }
    }
    while(!q.empty()) {
        auto v = -q.top();
        q.pop();
        topo.pb(v);
        for(auto x : g[v]) {
            indegree[x]--;
            if(indegree[x] == 0)    q.push(-x);
        }
    }
}

int main() {
    
    cin >> n >> m;
    f(i, 1, m) {
        int a, b; cin >> a >> b;
        g[b].pb(a);
        indegree[a]++;
    }

    bfs();

    f(i, 0, sz(topo) - 1)
        cout << topo[i] << " \n"[i == sz(topo) - 1];
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Longest Path in DAG------------------------------------------

Hint: Graph DP problem

-----------------------------------------------------------------------------------------*/
// End of application of Topological ordering : 

/*-----------------------------Problem_to_be_done (needs 01-BFS)-------------------------------------------

// Problem : Given an array A of size N, you start at index 1 and want to 
//           find the shortest path to every node 2<= i <=N. From an index X, in 1 second,
//           you can go to the indexes X+1 and X-1 (if they exist), or to any index with
//           the same value as A[X] (any Y where A[Y]=A[X]).

int n;
vector<int> v;
vector<int> vis;
vector<int> vv[100100];


void solve() {

}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

// -------------------------------------------------------------------------------------*/

/*-----------------------------01-BFS()-----------------------------------------------------

// Can also act as multi src BFS01() -> just push all src(s) initially in deque.

// Same code can act as BFS() for weighted graphs. Only make Changes: 
//     1. make deque -> queue
//     2. remove if(weigh){...} part

vector<pair<int, int>> g[100100];
int dist[100100];      // here also acts as vis[ ]
int n, m;

void BFS01(int src) {

    f(i, 1, n)  dist[i] = 1e9;

    dist[src] = 0;
    
    deque<int> dq;
    dq.push_back(src);
    while(!dq.empty()) {
        auto u = dq.front();
        dq.pop_front();

        for(auto v : g[u]) {
            int neigh = v.ff;
            int weigh = v.ss;
            if(dist[neigh] > dist[u] + weigh) {  // if (dist[v] <= dist[u] + wt) => v is visited, no need to vis.again
                dist[neigh] = dist[u] + weigh;

                if(weigh)   
                    dq.push_back(neigh);
                else    
                    dq.push_front(neigh);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;        // c-> {0, 1}
        g[a].pb({b, c});
        g[b].pb({a, c});
    }

    int src; cin >> src;
    BFS01(src);

    f(i, 1, n)
        cout << dist[i] << " \n"[i == n];
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

//i/p:
// 7 7
// 1 2 1
// 1 3 1
// 1 4 1
// 4 5 0
// 4 6 1
// 5 6 0
// 6 7 1
// 1

//o/p: 0 1 1 1 1 1 2

-------------------------------------------------------------------------------------*/

// Problems of BFS01()
/*-----------------------------Minimum changes to reach destination------------------------


// Problem: Given a direction matrix of (N x M):(N, M <= 1000).
//          Find the min. number of directions we need to change to reach
//          from (0, 0) to (N - 1, M - 1). 

vector<vector<int>> dis;
vector<string> v;
int n, m;

// dir :    r  d   u  l
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool check(int x, int y) {
    return (x < n and x >= 0 and y < m and y >= 0);
}

void BFS01(int x, int y) {
    dis[x][y] = 0;
    deque<pair<int, int>> dq;
    dq.pb({x, y});

    while(!dq.empty()) {
        auto u = dq.front();
        dq.pop_front();

        f(i, 0, 3) {
            if(check(u.ff + dx[i], u.ss + dy[i])) {
                int cost = 1;
                if(i == 0 and v[u.ff][u.ss] == 'r') cost = 0; 
                else if(i == 1 and v[u.ff][u.ss] == 'd') cost = 0; 
                else if(i == 2 and v[u.ff][u.ss] == 'u') cost = 0; 
                else if(i == 3 and v[u.ff][u.ss] == 'l') cost = 0;

                if(dis[u.ff + dx[i] ][u.ss + dy[i] ] > dis[u.ff][u.ss] + cost) {
                    dis[u.ff + dx[i] ][u.ss + dy[i] ] = dis[u.ff][u.ss] + cost;
                    if(!cost) {
                        dq.push_front({u.ff + dx[i], u.ss + dy[i]});
                    }
                    else {
                        dq.pb({u.ff + dx[i], u.ss + dy[i]});
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    
    v.resize(0);
    dis.clear();
    dis = vector<vector<int>> (n, vector<int>(m, 1e9));
    
    f(i, 0, n - 1) {
        string s; cin >> s;
            v.pb(s);
    }

    BFS01(0, 0);

    cout << dis[n - 1][m - 1] << endl;
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

//i/p:
// 4 4
// rrrr
// llll
// rrrr
// llll

//o/p: 3

-------------------------------------------------------------------------------------*/
// 1. One more problem to be done
// 2. Extended version of 01-BFS -> (Read Dial's Algorithm  -> Extra🤯)

/*-----------------------------Dijkstra's Algorithm (SSSP for weighted G(V, E))-----------------
// Read CP3(by S.Halim) for more details , if needed

// BFS finds the shortest path (in terms of no. of egdes) from src to all other nodes.
// Dijkstra finds the shortest path (in terms of sum of edge wt(s)) from src to all other nodes. 

// ⭐IDEA⭐: Fix the dist of closest node reachable(from frontier) and relax other edges 
//            that are connected to it.

vector<pii> g[100100];
ll dist[100100];          // ll is made intentionally as th dist may overflow int
int vis[100100];
int n, m;

class prioritize {
    public: 
        bool operator ()(pii &p1 , pii &p2) {
            return p1.ss > p2.ss;
        }
};

void Dijkstra(int src) {
    f(i, 1, n) {           // for testcases only
        dist[i] = 1e18;
        vis[i] = 0;
    }

    dist[src] = 0;
    priority_queue<pii, vector<pii>, prioritize> pq;
    pq.push({src, 0});
    
    while(!pq.empty()) {
        auto fs = pq.top();
        pq.pop();

        if(vis[fs.ff])  continue;                 // since same node can be inserted in pq with different wt(s), but once a node is visited means its min_cost is already fixed as reaching the node again would add more edges to the path making the cost to reach the node bigger. so we are preventing to visit the same node again through this line of code, though this is not compulsory.
        vis[fs.ff] = 1;

        for(auto v : g[fs.ff]) {                  // relaxing all the neighbours 
            int neigh = v.ff, wt = v.ss;
            if(dist[neigh] > dist[fs.ff] + wt) {
                dist[neigh] = dist[fs.ff] + wt;
                pq.push({neigh, dist[neigh]});    // adding new set of egdes to pq for exploration (from the next iter.) based on min. edge wts(s)
            } 
        }
    }
}

void solve() {    
    cin >> n >> m;
    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }

    Dijkstra(1);    // 1-> start node

    f(i, 1, n)  cout << dist[i] << " \n"[i == n]; 
    // vis[ ] has all the nodes that can be visited from src  
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

//i/p:
// 4 5
// 1 2 1
// 1 3 4
// 1 4 7
// 3 4 2
// 2 3 1

//o/p: 0 1 2 4

// Try 2 problems given in videos on application of dijkstra algorithm (AlgoZenith).

------------------------------------------------------------------------------------*/

/*-----------------------------Bellman_Ford's Algorithm-----------------------------------------------------------

// (Brute Force)

vector<pii> g[100100];
ll dist[100100];
int n, m;

void Bellman(int src) {

    dist[src] = 0;

    f(i, 1, n - 1) {      // (|V| - 1) times relaxation
        f(u, 1, n) {      // relaxing each edge
            for(auto v: g[u]) {
                if(dist[v.ff] > dist[u] + v.ss) {
                    dist[v.ff] = dist[u] + v.ss;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    f(i, 1, n)  dist[i] = 1e18;

    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;
        g[a].pb({b, c});
    }

    Bellman(1);        // 1 -> start node
    cout << "After (N - 1) iter.(s)\n";
    f(i, 1, n)  cout << dist[i] << " \n"[i == n];

    // checking -ve cycle exists or not
    bool f = 1;
    f(u, 1, n) {
        for(auto v: g[u]) {
            if(dist[v.ff] > dist[u] + v.ss) {
                cout << "\n-ve cycle hai!!!\n" << endl;
                f = 0;
                break;
            }
        }
        if(!f) break;
    }
    if(f)   cout << "\n-ve cycle nhi hai\n";

    // finding vertices forming -ve cycles
    Bellman(1);
    cout << "After second (N - 1) iter.(s)\n";
    f(i, 1, n)  cout << dist[i] << " \n"[i == n];
    // values changed in dist[i] after 2nd (N - 1) iter. from 1st (N - 1) iter. form -ve cycle.
    // and nodes for which values are unchanged: dist[node] = SSSP(src, node);
}


int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

//i/p:
// 4 4
// 1 2 10
// 2 3 7
// 3 4 -5
// 4 2 -3

//o/p: 
// After (N - 1) iter.(s)
// 0 7 15 10

// -ve cycle hai!!!

// After second (N - 1) iter.(s)
// 0 4 12 7

------------------------------------------------------------------------------------*/

/*-----------------------------Floyd Warshall's Algorithm-----------------------------------------------------------

int dist[404][404];        // 400 becoz this algo. dies not work for n > 400
int par[404][404];         // for path
int n, m;

// void print_path(int i, int j) {    // printpath: i-> x-> j-> ... -> par[i][j]-> j
//     if(i != j)  
//         print_path(i, par[i][j]);
//     cout << j << " -> ";
// }

void solve() {
    cin >> n >> m;
    // initialisation
    f(i, 0, n - 1) {                       // considering 0-based nodes in graph
        f(j, 0, n - 1) {
            if(i != j)  dist[i][j] = 1e9;
        }
    }
    // G(V, E) i/p
    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);   // to handle multi-edges b/w (a)-->(b) in G(V, E)
    }
    // floyd's algor.
    f(k, 0, n - 1) {
        f(i, 0, n - 1) {
            f(j, 0, n - 1) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // dist[a][b] gives the SP from a to b
    f(i, 0, n - 1) {
        f(j, 0, n - 1) {
            cout << dist[i][j] << "\t\n"[j == n - 1];
        }
    }    

    // // how to print paths ????
    // f(i, 0, n - 1) {
    //     f(j, 0, n - 1) {
    //         par[i][j] = i;
    //     }
    // }
    // f(k, 0, n - 1) {
    //     f(i, 0, n - 1) {
    //         f(j, 0, n - 1) {
    //             if(dist[i][j] > dist[i][k] + dist[k][j]) {
    //                 dist[i][j] = dist[i][k] + dist[k][j];
    //                 par[i][j] = par[k][j];
    //             }
    //         }
    //     }
    // }
    // print_path(3, 2);
    // cout << endl;

    // Thik se socho dist[][] matrix se hi closure(i) mil jayega
        // reachable[i][j] = (i == j) or (dist[i][j] != INF) or (dist[i][k] != INF and dist[k][j] != INF)
        // or for bool g[i][j] => g[i][j] |= (g[i][k] and g[k][j]); for all i,j,k => see copy
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}


//i/p:  (CB Example)
// 4 5
// 1 0 4
// 0 2 -2
// 1 2 3
// 3 1 -1
// 2 3 2

//o/p:
// path(3, 2):  3 -> 1 -> 0 -> 2 -> 
// 0	-1	-2	0
// 4	0	2	4
// 5	1	0	2
// 3	-1	1	0

------------------------------------------------------------------------------------*/

// Application of Floyd's algorithm :
/*-----------------------------Transitive_closure--------------------------------------------------------

// finding transitive closure for a node(i) -> what all nodes are reachable from node(i)
// j can be reached through direct egde or through some node(k)
// i.e. either (i-> j) or (i-> k-> j)

int dist[404][404];       // all g[i][j] = 0, automaitcally       
int n, m;

void solve() {
    cin >> n >> m;

    // G(V, E) i/p
    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = 1;
    }

    int i = 0;
    while(i < n) {
        dist[i][i] = 1;
        i++;
    }

    // floyd's algor.
    f(k, 0, n - 1) {
        f(i, 0, n - 1) {
            f(j, 0, n - 1) {
                dist[i][j] |= (dist[i][k] and dist[k][j]);
            }
        }
    }

    // closure
    f(i, 0, n - 1) {
        f(j, 0, n - 1) {
            cout << dist[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

//i/p:
// 7 7
// 0 1 1
// 1 3 -1
// 1 2 2
// 3 5 -2
// 4 2 6
// 4 5 4
// 6 4 3

//o/p:
// 1 1 1 1 0 1 0
// 0 1 1 1 0 1 0
// 0 0 1 0 0 0 0
// 0 0 0 1 0 1 0
// 0 0 1 0 1 1 0
// 0 0 0 0 0 1 0
// 0 0 1 0 1 1 1

------------------------------------------------------------------------------------*/

/*-----------------------------Detecting -VE cycles in G(V, E)--------------------------------------------------------

// detect +ve cycles : for every i, if(dist[i][i] < 1e9) => yes : no
// run this and print dist[i][j] to see why the idea won't work
// 5 5
// 0 1 -1
// 1 2 -1
// 2 3 -1
// 3 4 -1
// 0 4 -1

int dist[404][404];       // all g[i][j] = 0, automatically       
int n, m;

void solve() {
    cin >> n >> m;
    f(i, 0, n - 1) {
        f(j, 0, n - 1) {
            dist[i][j] = 1e9; // check if(i != j)... not needed
        }
    }
    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
    }

    f(k, 0, n - 1) {
        f(i, 0, n - 1) {
            f(j, 0, n - 1) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int mn = 1e9;
    f(i, 0, n - 1) {
        mn = min(mn, dist[i][i]);
    }
    
    if(mn < 0) {
        cout << "-VE cycle hai !!!" << endl;
        cout << "Cheapest cycle : " << mn / 2 << endl;
    }  
    else  cout << "-VE cycle nhi hai !!!" << endl;

}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}

------------------------------------------------------------------------------------*/

// /*-----------------------------Diameter of a G(V, E)-----------------------------------------------------------

// Diameter of a G(V, E) is the length of longest shortest path (max_cost SP). 
// Idea: Run normal floyd's algo on G(V, E) and take max 0f all dist[i][j]: dist[i][j] != INF

#define int ll
int dist[404][404];       // all g[i][j] = 0, automatically       
int n, m;

void solve() {
    cin >> n >> m;

    f(i, 0, n - 1) {
        f(j, 0, n - 1) {
            if(i != j)  dist[i][j] = 1e9;
        }
    }

    // G(V, E) i/p
    f(i, 1, m) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);       // there can be multi-edges
    }

    // floyd's algo.
    f(k, 0, n - 1) {
        f(i, 0, n - 1) {
            f(j, 0, n - 1) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // finding diameter
    ll dia = INT_MIN;
    f(i, 0, n - 1) {
        f(j, 0, n - 1) {
            if(dist[i][j] != 1e9) {
                dia = max(dia, dist[i][j]);
            }
        }
    }

    cout << "Diameter: " << dia << endl;
}

signed main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("io/Error.txt", "w", stderr);
    #endif
    // int _t = 1; cin >> _t; while(_t--)
    solve();
}
// ------------------------------------------------------------------------------------*/
// End of application of Floyd's algorithm :
