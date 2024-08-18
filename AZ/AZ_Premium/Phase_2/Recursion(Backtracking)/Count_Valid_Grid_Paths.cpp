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
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif
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

string s;
int vis[7][7];
//           U  L  D  R
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool chk(int x, int y) {
    return (x >= 0 and x <= 6 and y >= 0 and y <= 6 and vis[x][y] == 0);
}

ll rec(int lvl, int i, int j) {
    if(lvl == s.size()) {
        return (i == 6 and j == 0);
    }

    if(lvl != s.size() and i == 6 and j == 0)   return 0;

    if( ((i - 1 < 0 or vis[i - 1][j]) and (j - 1 >= 0 and !vis[i][j - 1]) and (j + 1 < 7 and !vis[i][j + 1])) or 
        ((i + 1 >= 7 or vis[i + 1][j]) and (j - 1 >= 0 and !vis[i][j - 1]) and (j + 1 < 7 and !vis[i][j + 1])) or
        ((j - 1 < 0 or vis[i][j - 1]) and (i - 1 >= 0 and !vis[i - 1][j]) and (i + 1 < 7 and !vis[i + 1][j])) or
        ((j + 1 >= 7 or vis[i][j + 1]) and (i - 1 >= 0 and !vis[i - 1][j]) and (i + 1 < 7 and !vis[i + 1][j])) )
            return 0;


    ll cnt = 0;
    if(s[lvl] == '?') {
        for(int k = 0; k <= 3; ++k) {
            if(chk(i + dx[k], j + dy[k])) {
                vis[i + dx[k]][j + dy[k]] = 1;
                cnt += rec(lvl + 1, i + dx[k], j + dy[k]);
                vis[i + dx[k]][j + dy[k]] = 0;
            }
        }
    }
    else {
        string dir = "ULDR";
        for(int x = 0; x <= 3; x++) {
            if(s[lvl] == dir[x]) {
                if(chk(i + dx[x], j + dy[x])) {
                    vis[i + dx[x]][j + dy[x]] = 1;
                    cnt += rec(lvl + 1, i + dx[x], j + dy[x]);
                    vis[i + dx[x]][j + dy[x]] = 0;
                }
            }
        }
    }
    return cnt;
}

void solve()
{
    cin >> s;
    vis[0][0] = 1;
    cout << rec(0, 0, 0);
}

// JUST ONE MISTAKE, AND YOU ARE HAHAHAHHHHHHHHHHAAAAAAAAAAAAAAA!!!
/* Wo sare problems karo jo lage ki ho jayega but nhi ho pata */

int main()
{
    fastio();
    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}
    // if (((i + 1 == 7 || (vis[i - 1][j] && vis[i + 1][j])) && j - 1 >= 0 && j + 1 < 7 && !vis[i][j - 1] && !vis[i][j + 1]) ||
    //     ((j + 1 == 7 || (vis[i][j - 1] && vis[i][j + 1])) && i - 1 >= 0 && i + 1 < 7 && !vis[i - 1][j] && !vis[i + 1][j]) ||
    //     ((i == 0 || (vis[i + 1][j] && vis[i - 1][j])) && j - 1 >= 0 && j + 1 < 7 && !vis[i][j - 1] && !vis[i][j + 1]) ||
    //     ((j == 0 || (vis[i][j + 1] && vis[i][j - 1])) && i - 1 >= 0 && i + 1 < 7 && !vis[i - 1][j] && !vis[i + 1][j]))
    //     return 0;