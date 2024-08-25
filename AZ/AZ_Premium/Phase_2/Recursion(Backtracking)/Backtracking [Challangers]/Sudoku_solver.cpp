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
#define P 1000000007
#define P1 998244353
#define llINT_MAX 9e18
#define iINT_MAX 1e9
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mkp make_pair
#define ff first
#define ss second
#define vii vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define p_q priority_queue
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define yes cout << "Yes" << "\n"
#define no cout << "No" << "\n"
#define gg cout << -1 << "\n"
#define ln cout << "\n"
#define re return
template <class T> istream& operator >> (istream &is, vector<T> &v) { for(auto &i : v)    is >> i; return is; };
template <class T> ostream& operator << (ostream &os, vector<T> &v) { for(auto &i : v)    os << i << " "; cout << "\n"; return os; };
// #ifndef ONLINE_JUDGE
// #include <algo/debug.h>
// #else
// #define dbg(...) ;
// #define debug(...) ;
// #define crndl ;
// #endif

// //---- Debugger ---- //
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define debvec(vec) cerr<<#vec<<" :\n";for(int i=0;i<(int)vec.size();i++) {for(int j=0;j<(int)vec[i].size();j++) cerr<<vec[i][j]<<" ";cerr<<endl;}
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
// ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//--------Mine Added (Inspiration : Vivek Gupta)--------- //
#define crndl cerr << "\n";
template <class T>ostream& operator <<(ostream& os, queue<T> p){ os << "[ "; while(!p.empty()) { os << p.front() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream &os, stack<T> p){ vector<T> v; while (!p.empty()) { v.push_back(p.top()); p.pop(); } reverse(all(v)); os << "[ " << v << "]"; return os; }
template <class T>ostream& operator <<(ostream &os, priority_queue<T> p){ os << "[ "; while (!p.empty()) { os << p.top() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream &os, priority_queue<T,vector<T>, greater<T>> p){ os << "[ "; while (!p.empty()) { os << p.top() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream& os, const deque<T> &p){os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// //------------------------------------------------------- //



long long POW(long long a,long long b){return (long long)(pow(a,b)+0.5);}
long long gcd(long long a,long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return (a*b)/__gcd(a,b);}
long long Ceil(long long a,long long b){return (a+b-1)/b;}
long long Sqrt(long long x){ long long y=sqrt(x)+5;while(y*y>x)y--;return y;}
long long sq(long long x){return (1ll*x*x);}
/*-------------------> Greedy / Constructive <----------------------
                        D T D P G B
⭐ D -> Decode the operation
⭐ T -> Think in reverse
⭐ D -> Dimensional Setup
⭐ P -> Prefix or Suffix ideas
⭐ G -> Greedy / Sorting
⭐ B -> Bit Manipulation
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int n;
vector<vector<int>> board;

bool can_place(int ch, int i, int j) {
    bool ok = 1;
    f(r, 0, n - 1) {
        if(r == i)  continue;
        if(board[r][j] == ch)   return 0;
    }
    f(c, 0, n - 1) {
        if(c == j)  continue;
        if(board[i][c] == ch)   return 0;
    }

    int str = i/Sqrt(n) * Sqrt(n), stc = j/Sqrt(n) * Sqrt(n);
    f(dx, 0, Sqrt(n) - 1) {
        f(dy, 0, Sqrt(n) - 1) {
            int ni = str + dx, nj = stc + dy;
            if(ni == i and nj == j) continue;
            if(board[ni][nj] == ch)     return 0;
        }
    }
    // pr(ch, ok);
    return 1;
}

void rec(int level) {
    if(level == n*n) {
        f(i, 0, n - 1) {
            f(j, 0, n - 1) {
                cout << board[i][j] << " ";
            }
            ln;
        }
        re;
    }

    int i = level / n, j = level % n;

    if(board[i][j] != 0) {
        rec(level + 1);
    }
    else {
        f(ch, 1, n) {
            if(can_place(ch, i, j)) {
                board[i][j] = ch;
                rec(level + 1);
                board[i][j] = 0;
            }
        }
    }
}

void solve()
{
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    
    f(i, 0, n - 1) f(j, 0, n - 1) {
        cin >> board[i][j];
    }
    rec(0);
}

// Method 2: (Pruned all the cases after a solution is achieved ----------------------------------

bool rec1(int level) {
    if(level == n*n) {
        f(i, 0, n - 1) {
            f(j, 0, n - 1) {
                cout << board[i][j] << " "; 
            }
            ln;
        }
        return 1;
    }

    int i = level /n, j = level % n;

    if(board[i][j] != 0) {
        return rec1(level + 1);
    }

    bool is_solved = 0;
    f(ch, 1, n) {
        if(can_place(ch, i, j)) {
            board[i][j] = ch;
            is_solved = rec1(level + 1);
            if(is_solved)   return is_solved;
            board[i][j] = 0;
            
        }
    }
    return is_solved;
}

void solve1() {
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    
    f(i, 0, n - 1) f(j, 0, n - 1) {
        cin >> board[i][j];
    }
    rec1(0);
}

// JUST ONE MISTAKE, AND YOU ARE HAHAHAHHHHHHHHHHAAAAAAAAAAAAAAA!!!
/* Wo sare problems karo jo lage ki ho jayega but nhi ho pata */

int main()
{
    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("io/Error.txt", "w", stderr);
    //     // freopen("io/Input.txt", "r", stdin);
    //     // freopen("io/Output.txt", "w", stdout);
    // #endif

    // int _t; cin >> _t; while(_t--)
    // solve();
    solve1();
    return 0;
}
        