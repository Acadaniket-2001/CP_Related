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
#define F first
#define S second
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
#define debvmat(vec) cerr << #vec << " :\n"; for (auto r: vec) { for (auto c: r) cerr << c << "\t"; cerr << endl; }  // Mine added.
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
#define debvec(vec){}
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
Flow:   WAP to print the shortest dist b/w S -> F
        optimise vis[][] using dis[][]
        print dis[][]
        print path S -> F

        ..follow_ups..
        Count all shortest paths S -> F
        Find shortest path if it is allowed to break atmost K walls.
        ...
*/

/*
6 6
S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
F . . . . .

Problem : 1. Find the shortest path from S -> F
          2. Print the path from S -> F
          
          3. Count the number of shortest path from S -> F (Day_15--> Number_of_SP_Using_BFS.cpp)
          4. Find the minimum of walls needed to break to reach from 'S' -> 'F' (Day_15--> Number_of_Walls_to_Break.cpp)
          5. Given K(TNT), find the SP from 'S' -> 'F' (Day_15--> K_TNT.cpp)
*/
#define INF 100   // just for this problem




int n, m;
vector<vector<char>> arr;
using state = pair<int, int>;                                                        // ⭐

// vector<vector<int>> vis;
vector<vector<int>> dis;                                                             // ⭐ using dis[ ] as vis[ ]  => if dis[i][j] == INF -> (i, j): !vis |||||  only possible in bfs() becoz each node is visited only once in bfs()
vector<vector<state>> par;                                                           // ⭐ for printing path

bool is_valid(int x, int y) {
    return (x>=0 and x<n and y>=0 and y<m and arr[x][y] != '#');
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};                                                            // ⭐ since symmetry about 45° -> shift it by 1/4

// int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

vector<state> neighbours(state node) {
    vector<state> neighs;
    f(i, 0, 3) {
        int x = node.F + dx[i];
        int y = node.S + dy[i];
        if(is_valid(x, y)) {
            neighs.pb({x, y});
        }
    }
    return neighs;
}

void bfs(state st) {
    // vis.assign(n, vector<int>(m, 0));                                             // ⭐  -> good practice to resize in bfs()
    dis.assign(n, vector<int>(m, INF));
    par.assign(n, vector<state>(m, {-1, -1}));

    queue<state> q;

    // vis[st.F][st.S] = 1;
    dis[st.F][st.S] = 0;
    par[st.F][st.S] = {-1, -1};
    q.push(st);
    
    while(!q.empty()) {
        state node = q.front(); q.pop();
        for(auto v: neighbours(node)) {
            // if(!vis[v.F][v.S]) {
            if(dis[v.F][v.S] == INF) {

                // vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                par[v.F][v.S] = node;
                q.push(v);
            }
        }
    }
    
}

void print_path(state node) {                                                        // ⭐
    vector<state> path;

    state cur = node;
    while(cur != mkp(-1, -1)) {
        path.pb(cur);
        cur = par[cur.F][cur.S];
    }

    reverse(all(path));
    for(auto v: path)   cout << v << endl;
    ln; 
}

void solve()
{
    cin >> n >> m;
    state st, en;

    arr.resize(n);
    f(i, 0, n - 1) {
        arr[i].resize(m);                                                            // ⭐
        f(j, 0, m - 1)  {
            cin >> arr[i][j];
            if(arr[i][j] == 'S')    st = {i, j};
            if(arr[i][j] == 'F')    en = {i, j};
        }  
    }

    bfs(st);
    if(dis[en.F][en.S] != INF) {
        cout << dis[en.F][en.S] << endl;
        print_path(en);
    }
    else 
        cout << "Finish is not reachable !!!" << endl;

    debvmat(dis);
}

int main()
{
    fastio();
    solve();
    return 0;
}

// T.C. = O(V + E) = O(n*m + 4*(n*m)) = O(n*m);