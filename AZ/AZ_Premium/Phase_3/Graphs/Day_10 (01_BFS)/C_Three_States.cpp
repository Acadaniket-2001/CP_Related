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

// Problem: https://codeforces.com/contest/590/problem/C

#define INF 1e9

using state = pair<int, int>;
int n, m;
vector<string> g;
vector<state> one, two, three;
vector<vector<vector<int>>> dis;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool is_valid(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

bool can_relax(state node, int x, int y, int comp_type) {
    // {node} --->{x, y}
    // {x, y} == '.' ==> cost = 1; else cost = 0;
    int cost = (g[x][y] == '.');
    return (dis[comp_type][x][y] > dis[comp_type][node.ff][node.ss] + cost);
}

void mbfs_01(vector<state> st) {
    int comp_type = 0;
    if(g[st[0].ff][st[0].ss] == '1')  comp_type = 1;
    else if(g[st[0].ff][st[0].ss] == '2')  comp_type = 2;
    else if(g[st[0].ff][st[0].ss] == '3')  comp_type = 3;

    deque<state> dq;
    for(auto e: st) {
        dis[comp_type][e.ff][e.ss] = 0;
        dq.push_back(e);
    }

    while(!dq.empty()) {
        state node = dq.front(); dq.pop_front();

        f(i, 0, 3) {
            int x = node.ff + dx[i];
            int y = node.ss + dy[i];
            if(is_valid(x, y) and g[x][y] != '#' and can_relax(node, x, y, comp_type)) {
                int cost = (g[x][y] == '.');
                dis[comp_type][x][y] = dis[comp_type][node.ff][node.ss] + cost;
                if(cost)
                    dq.push_back({x, y});
                else   
                    dq.push_front({x, y});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n);
    dis.resize(4, vector<vector<int>>(n, vector<int>(m, INF)));

    f(i, 0, n - 1) {
        cin >> g[i];
    }

    f(i, 0, n - 1) {
        f(j, 0, m - 1) {
            if(g[i][j] == '1')  one.pb({i, j});
            else if(g[i][j] == '2')  two.pb({i, j});
            else if(g[i][j] == '3')  three.pb({i, j});
        }
    }

    mbfs_01(one);
    mbfs_01(two);
    mbfs_01(three);

    ll ans = 1e15;
    f(i, 0, n - 1) {
        f(j, 0, m - 1) {
            if(g[i][j] != '#') {
                
                if(dis[1][i][j] == INF or dis[2][i][j] == INF or dis[3][i][j] == INF)   continue;

                ll path_cost = dis[1][i][j] + dis[2][i][j] + dis[3][i][j];
                pr(i, j, dis[1][i][j], dis[2][i][j], dis[3][i][j]);
                if( g[i][j] == '.')  path_cost -= 2;
                ans = min(ans, path_cost); 
            }
        }
    }

    if(ans == 1e15)
        cout << -1 << endl;
    else 
        cout << ans << endl;
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