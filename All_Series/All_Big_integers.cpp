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
// ganit  
/*-------------------> Current Level <----------------------
1. Think brute force
2. Think all possibilities
3. Think greedy
4. Think sortings
5. Think constructive algorithms
6. Think implementation
7. Think math
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void sum()
{
    int n; cin >> n;
    vector<int> n1(n);
    rf(i, n - 1, 0)    cin >> n1[i];
    dbg(n1)
    
    int m; cin >> m;
    vector<int> n2(m);
    rf(i, m - 1, 0)    cin >> n2[i];
    dbg(n2)

    vector<int> add(max(n, m) + 1);

    int carry = 0;
    f(i, 0, sz(add) - 1) {
        int s = 0;
        if(i < n)   s += n1[i];
        if(i < m)   s += n2[i];
        s += carry;

        add[i] = s % 10;
        carry = s / 10;
    }
    reverse(all(add));
    for(auto x : add)   cout << x << " ";
    cout << endl;
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
    sum();
    return 0;
}

