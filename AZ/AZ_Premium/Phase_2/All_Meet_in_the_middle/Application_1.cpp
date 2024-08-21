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

// Problem: Given n rods, can we join them in some order to form a square. All the rods must be used.





// // M1 -> Doing Brute Force using Recursion
// int n;
// vector<int> rods;

// bool rec(int i, int a, int b, int c, int d, int side) {      // O(4^n) so, mx(n) = 10
//     if(i == n) {
//         return (a == b and b == c and c == d);
//     }

//     bool ok = 0;
//     if(a + rods[i] <= side)    ok |= rec(i + 1, a + rods[i], b, c, d, side);
//     if(b + rods[i] <= side)    ok |= rec(i + 1, a, b + rods[i], c, d, side);
//     if(c + rods[i] <= side)    ok |= rec(i + 1, a, b, c + rods[i], d, side);
//     if(d + rods[i] <= side)    ok |= rec(i + 1, a, b, c, d + rods[i], side);

//     return ok;
// }

// void solve_brute()
// {
//     cin >> n;
//     rods.assign(n, 0); cin >> rods;
//     int side = accumulate(all(rods), 0);
//     if(side % 4)  {
//         cout << 0 << endl;
//         re;
//     }

//     side /= 4;
//     cout << rec(0, 0, 0, 0, 0, side) << endl;      // rec(i, a, b, c, d)
// }






// // M2 -> Optimising M1 using Meet in the middle
int n;
vector<int> rods;
int side;

// accumulator parameterised in generate(...st...)

//partial solution
vector<int> curr(4, 0);


void generate(int i, vector<int>& v, set<vector<int>>& st) {         // O(4^n)
    if(i == v.size()) {
        st.insert(curr);
        re;
    }

    // choices --> add to curr[0] or curr[1] or curr[2] or curr[3]
    if(curr[0] + v[i] <= side) {
        curr[0] += v[i];
        generate(i + 1, v, st);
        curr[0] -= v[i];
    }
    if(curr[1] + v[i] <= side) {
        curr[1] += v[i];
        generate(i + 1, v, st);
        curr[1] -= v[i];
    }
    if(curr[2] + v[i] <= side) {
        curr[2] += v[i];
        generate(i + 1, v, st);
        curr[2] -= v[i];
    }
    if(curr[3] + v[i] <= side) {
        curr[3] += v[i];
        generate(i + 1, v, st);
        curr[3] -= v[i];
    }
}

void solve_brute_optimised()             // O(n.4^(n/2))    ----> mx(n) = 20❤️
{
    cin >> n;
    rods.assign(n, 0); cin >> rods;
    side = accumulate(all(rods), 0);
    if(side % 4)  {
        cout << 0 << endl;
        re;
    }
    side /= 4;

    vector<int> newarr[2];
    f(i, 0, n - 1)  // O(n)                         
        newarr[i&1].pb(rods[i]);

    set<vector<int>> sub0, sub1;
    generate(0, newarr[0], sub0);   // O(4^(n/2))
    generate(0, newarr[1], sub1);   // O(4^(n/2))

    for(auto e: sub0) {          // O(4^(n/2)*log(4^(n/2)))  =  O(n.4^(n/2))
        vector<int> complement = {side - e[0], side - e[1], side - e[2], side - e[3]};
        if(sub1.find(complement) != sub1.end()) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}



// JUST ONE MISTAKE, AND YOU ARE HAHAHAHHHHHHHHHHAAAAAAAAAAAAAAA!!!
/* Wo sare problems karo jo lage ki ho jayega but nhi ho pata */

int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("io/Error.txt", "w", stderr);
        // freopen("io/Input.txt", "r", stdin);
        // freopen("io/Output.txt", "w", stdout);
    #endif

    int _t; cin >> _t; while(_t--)
    // solve_brute( );
    solve_brute_optimised( );
    return 0;
}