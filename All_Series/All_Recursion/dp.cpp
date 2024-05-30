#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i,a,b) for(long long i=a;i<=b;i++)
#define rrep(i,a,b) for(long long i=a;i>=b;i--)
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
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// to get custom MOD(m), modify line no. 8
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_expo(ll a, ll n) { ll res = 1; while(n) { if(n % 2)   res = mod_mul(res, a), n--; else a  = mod_mul(a, a), n /= 2; } return res; }
ll mod_inv(ll a) { return mod_expo(a, MOD - 2); }   //MOD must be prime ; (a, MOD) -> coprime
ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)); }

//------------------------------------------------------------------------------------------------------------------------------------------

/*                          Common Errors :-
    # use INT_MAX -> llINT_MAX
    1.  int dp[5004][5004]; can't be declared locally(gives SIGTERM) instead globally.

    2.  For multiple test cases write memset() inside while(t--) { memset( ... ) }..

    3.  For subset generation -> brute force -> safely(N <= 20)

*/



/*
                            Basic steps to write a Recursive DP

    1. Decide DP state variables, write what dp(i, j, .): represents.

    2. Find which dp state has our required solution.

    3. Write the transitions.

    4. Think about the base cases.

*/

/*
                            Recursive DP ---->> Iterative DP
    
    1.  Decide the order of computation --->>  it is decided such that when we reach some state , 
        all smaller subproblems required to compute the present state of DP is already computed and stored in DP array. 
        
    2.  Replace DP state variables with loop iterators.
        Replace every recurrence call or return statement with statement like dp[][]...

    3.  No, lookup required.

*/

/*
    1.  GAME_DP or Project_Estimation :-  Assume worst when things happen to you
                                          Do best when you can.

    2.  DP on strings can be applied from [0 -> |s| - 1] or [|s| - 1 -> 0]

    3.  For Grid based DP, bottomup approach is the easiest one. 

    4. Try doing dp solutions from idx (n - 1) -> 0.
     
*/

/*-----------------------------Fibonacci_Numbers()--------------------------------------------------------

int dp[100005];

//Recursive Approach
int fibo(int n) {
    if(n == 0 || n == 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}


//Top_down Approach
int fiboTD(int n) {
    if(n == 0 || n == 1)
        return dp[n] = n;

    if(dp[n] != 0)
        return dp[n];
    
    return dp[n] = fiboTD(n - 1) + fiboTD(n - 2);
}

//Bottom_up Approach
int fiboBU(int n) {
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    } 
    return dp[n];
}

//Space optimisation
int fiboSpace(int n) {
    int a = 0, b = 1,c = 0;
    if(n == 0)  return a;
    if(n == 1)  return b;

    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n; cin >> n;
    cout << fibo(n) << endl;
    cout << fiboTD(n) << endl;
    cout << fiboBU(n) << endl;
    cout << fiboSpace(n) << endl;

    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Min_steps_to_one--------------------------------------------------------

int dp[10004];
int minSteps(int n) 
{
    // Base case
    if(n == 1)
        return 0;

    //lookup
    if(dp[n] != -1)
        return dp[n];
    
    //calculate
    int ans = INT_MAX;
    if(n % 3 == 0)
        ans = minSteps(n / 3);
    if(n % 2 == 0)
        ans = min(ans, minSteps(n / 2));
    ans = min(ans, minSteps(n - 1));

    return dp[n] = ans + 1;    
}

int minStepsBU(int n) {
    int dp1[10004];
    memset(dp1, -1, sizeof(dp));
    dp1[1] = 0;
    for(int i = 2; i <= n ;i++) {
        
        int ans = INT_MAX;
        if(i % 3 == 0)
            ans = dp1[i / 3];
        if(i % 2 == 0)
            ans = min(ans, dp1[i / 2]);
        ans = min(ans, dp1[i - 1]);
        dp1[i] = ans + 1;
    }
    return dp1[n];
}

void solve() {
    int n; cin >> n;
    cout << minSteps(n) << endl;
    cout << minStepsBU(n) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    while(t--)
        solve();
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------⭐ Min_coin_change ⭐--------------------------------------------------------

int dp[10004];
int notes(int n, const vector<ll>& prev) {
    
    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];
    
    int ans = INT_MAX;

    for(int i = 0; i < sz(prev); i++) {
        if(n >= prev[i]) {
            ans = min(ans, notes(n - prev[i], prev) + 1);
        }
    }
    return dp[n] = ans;
}

int notesBU(int n, const vector<ll>& prev) {
    int dp[10004] = {-1};

    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            dp[i] = 0;
            continue;
        }
    
        int ans = INT_MAX;
        for(int j = 0; j < sz(prev); j++) {
            if(i >= prev[j])
                ans = min(ans, dp[i - prev[j]] + 1);
        }
        dp[i] = ans;
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        vector<ll> prev(x);
        for(auto &s : prev)    cin >> s;
        int n; cin >> n;
        cout << notes(n, prev) << endl;
        cout << notesBU(n, prev) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Wine_Selling--------------------------------------------------------

// Greedy comes first in mind, but fails for sure

//Recursion
int maxProfit(const vector<int>& wine, int i, int j, int year) {
    if(i == j)
        return wine[i] * year;

    int prev_i = wine[i] * year;   
    int left = maxProfit(wine, i + 1, j, year + 1);

    int prev_j = wine[j] * year;
    int right = maxProfit(wine, i, j - 1, year + 1);
    
    return max(prev_i + left, prev_j + right);
}

//Top_Down_DP

int dp[10004][10004];
int maxProfitTD(vector<int>& wine, int i, int j, int year) {
    if(i == j)
        return dp[i][j] = wine[i] * year;

    if(dp[i][j] != 0)
        return dp[i][j];

    int prev_i = wine[i] * year;
    int left = maxProfit(wine, i + 1, j, year + 1);

    int prev_j = wine[j] * year;
    int right = maxProfit(wine, i, j - 1, year + 1);

    return dp[i][j] = max(prev_i + left, prev_j + right);
}

// try thinking BottomUP   ---->> a little complex

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> wine(n);
        for(auto &x: wine)  cin >> x;
        cout << maxProfit(wine, 0, n - 1, 1) << endl;    
        cout << maxProfitTD(wine, 0, n - 1, 1) << endl;        
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Catalan_numbers--------------------------------------------------------

// top_down / Memoisation / recursive DP
int dp[10004];
int catalan(int n) {
    if(n == 0)
        return 1;

    if(dp[n] != 0)
        return dp[n];
    
    // return dp[n] = (2 * (2*n - 1) * catalan(n - 1)) / (n + 1);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += catalan(i) * catalan(n - 1 - i);
    }
    return dp[n] = ans;
}

// bottom_up / tabulation / iterative DP
int catalanBU(int n) {
    int dp[n];
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            dp[i] = 1;
            continue;
        }

        // dp[i] = (2 * (2*i - 1) * dp[i - 1]) / (i + 1);

        dp[i] = 0;
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, 0, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // cout << catalan(n) << endl;
        cout << catalanBU(n) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Tilling_problem_DP--------------------------------------------------------

int dp[10004];
int ways(int n) {
    if(n < 0)
        return 0;
    
    if(n == 0)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = ways(n - 1) + ways(n - 4);
}

int waysBU(int n) {
    int dp[10004];
    for(int i = 0; i <= n; i++) {
        if(i < 0) {
            dp[i] = 0;
            continue;
        }
        
        if(i == 0) {
            dp[i] = 1;
            continue;
        }
        
        dp[i] = dp[i - 1] + dp[i - 4];
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << ways(n) << endl;
        // cout << waysBU(n) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Binary_strings_DP--------------------------------------------------------

int dp[10004];
int strings(int n){
    if(n < 0)
        return 0;
    
    if(n == 0)
        return 1;

    if(n == 1)
        return 2;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = strings(n - 1) + strings(n - 2);
}

int stringsBU(int n) {
    int dp[1004];
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            dp[i] = 1;
            continue;
        }

        if(i == 1) {
            dp[i] = 2;
            continue;
        }
        
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // cout << strings(n) << endl;
        cout << stringsBU(n) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

// try coding with 2D DP    --->> solution in CB video

/*-----------------------------Friends_Pairing--------------------------------------------------------

int dp[1004];
int ways(int n) {
    if(n <= 2) {
        return n;
    }

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = ways(n - 1) + (n - 1) * ways(n - 2);
}

int waysBU(int n) {
    int dp[1004];
    for(int i = 0; i <= n; i++) {
        if(i <= 2) {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i - 1] + (i - 1)*dp[i - 2];
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // cout << ways(n) << endl;
        cout << waysBU(n) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Coin_change--------------------------------------------------------

// int dp[100][100][100];
// int ways(int n, const vector<int>& coins, int i, int j) {
//     if(n == 0)
//         return 1;
    
//     if(n < 0 || i > j)
//         return 0;
    
//     if(dp[n][i][j] != -1)
//         return dp[n][i][j];

//     int op1 = ways(n - coins[i], coins, i, j);
//     int op2  =ways(n, coins, i + 1, j);

//     return dp[n][i][j] = op1 + op2;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     memset(dp, -1, sizeof(dp));

//     int t; cin >> t;
//     while(t--) {
//         int n, m; cin >> n >> m;
//         vector<int> coins(m);
//         for(auto &x : coins)    cin >> x;
//         cout << ways(n, coins, 0, m - 1) << endl;
//     }

//     return 0;
// }

-------------------------------------------------------------------------------------*/

/*-----------------------------Palindromic_queries--------------------------------------------------------

//Recursive
bool checkpal(const string& s, int i, int j) {
    if(i >= j)
        return 1;

    if(s[i] == s[j])
        return checkpal(s, i + 1, j - 1);
    return 0;
}

//Top_Down
int dp[100][100];
bool checkpalBU(const string &s, int i, int j) {
    if(i >= j)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[i] == s[j])
        return dp[i][j] = checkpalBU(s, i + 1, j - 1);

    return 0;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int q; cin >> q;
        while(q--) {
            int l, r; cin >> l >> r;
            l--, r--;
            // cout << (checkpal(s, l, r) ? "YES" : "NO") << endl;
            cout << (checkpalBU(s, l, r) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Maximum_Subarray_Sum--------------------------------------------------------

int maxSum(const vector<int>& v) {                       //O(n^3) --> Brute force
    int mx = INT_MIN, n = v.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += v[k];
            }
            mx = max(sum, mx);
        }
    }
    return mx;
}

int maxSum_m2(vector<int> v) {                          //O(n^2) --> Prefix Sum
    int sum = 0, n = v.size();
    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        v[i] = sum;
        mx = max(mx, v[i]);
    }

    for(int i = 1; i < n; i++) {
        for(int j = i; j < n; j++) {
            mx = max(mx, v[j] - v[i - 1]);
        }
    }

    return mx;
}

int maxSum_m3(const vector<int> &v) {          // O(n) --> Kadane's algo.(works like dp)
    // int dp[100] = {0};
    // dp[0] = v[0] > 0 ? v[0] : 0;
    // int max_so_far = dp[0];
    // for(int i = 1; i < v.size(); i++) {
    //     dp[i] = dp[i - 1] + v[i];
    //     if(dp[i] < 0)
    //         dp[i] = 0;
    //     max_so_far = max(max_so_far, dp[i]);
    // } 

    // return max_so_far;

    int max_till_now = 0, sum = 0;
    for(int i= 0; i <v.size(); i++) {
        sum += v[i];
        if(sum < 0)     sum = 0;
        max_till_now = max(max_till_now, sum);
    }
    return max_till_now;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // memset(dp, -1, sizeof(dp));

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        // cout << maxSum(v) << endl;
        // cout << maxSum_m2(v) << endl;
        cout << maxSum_m3(v) << endl;
    }

    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Ladder_Problem--------------------------------------------------------

int ways(int n ,int k) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += ways(n - i, k);
    }
    return ans;
}

//Top_down / Memoisation / Recursive Approach
int dp[10004];
int waysTD(int n, int k) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += ways(n - i, k);
    }

    return dp[n] = ans;
}

//Bottom_up / Tabulation / Iterative Approach
int waysBU(int n, int k) {
    int dp[10004];
    // memset(dp, -1, sizeof dp);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0)
                dp[i] += dp[i - j];
        }
    }

    for(int x = 0; x <= n; x++)
        cout << dp[x] << " ";
    cout << "\n";

    return dp[n];
}

int waysOpt(int n, int k) {             // can be used in all dp[] problems where
    int dp[10004];                      // cummulative sum type of thing is present
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i >= k - 1)
            dp[i] =2*dp[i - 1] - dp[i - k - 1];
        else
            dp[i] += dp[i - 1];
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        // cout << ways(n ,k) << endl;
        // cout << waysTD(n ,k) << endl;
        // cout << waysBU(n ,k) << endl;
        cout << waysOpt(n ,k) << endl;                  //uses sliding window technique
    }

    return 0;
}


-------------------------------------------------------------------------------------*/

/*-----------------------------Cell_Mitosis--------------------------------------------------------

int minCost(int n, int x, int y, int z) {

    int dp[1004] = {0};
    dp[0] = dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(i & 1)
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        else
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
    }
    return dp[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // memset(dp, -1, sizeof dp);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int x, y, z; cin >> x >> y >> z;
        cout << minCost(n, x, y, z) << endl;
    }

    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Bali_shoes--------------------------------------------------------

int ways(const vector<pair<int, int>>& shoes, int i, int j, int sum) {
    if(i == j) {
        int cnt = 0;
        if((sum + shoes[i].ff) & 1)     cnt++;
        if((sum + shoes[i].ss) & 1)     cnt++;
        return cnt;
    }

    int op1 = ways(shoes, i + 1, j, sum + shoes[i].ff);
    int op2 = ways(shoes, i + 1, j, sum + shoes[i].ss);
    return ((op1 % MOD) + (op2 % MOD)) % MOD;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // memset(dp, -1, sizeof dp);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> shoes;
        int x, y;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            shoes.pb({x, y});
        }
        cout << ways(shoes, 0, n - 1, 0) << endl;
    }

    return 0;
}

-------------------------------------------------------------------------------------*/

/* ----------------------------Matrix_Chain_Multiplication (MCM)---------------------------------------------------------

// recursive
int mcm(const vector<int>& v, int i, int j) {
    if(i == j)
        return 0;
    
    int ans = INT_MAX;
    for(int k = i; k <= j - 1; k++)
        ans = min(ans, mcm(v, i, k) + mcm(v, k + 1, j) + v[i]*v[k + 1]*v[j + 1]);
    return ans;
}

// top_down DP
int dp[200][200];
int mcmTD(const vector<int>& v, int i, int j) {
    if(i == j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = INT_MAX;
    for(int k = i; k <= j - 1; k++) {
        ans = min(ans, mcmTD(v, i, k) + mcmTD(v, k + 1, j) + v[i]*v[k + 1]*v[j + 1]);
    }

    return dp[i][j] = ans;
}

// bottom_up_DP
int mcmBU(const vector<int>& v) {
    int dp[200][200];
    int n = v.size() - 1;
    memset(dp, 0, sizeof dp);
    for(int x = 1; x < n; x++) {              // coded as it appeared in the matrix
        int r = 0, c = x;
        while(c < n) {
            int val = INT_MAX;
            for(int k = r; k < c; k++) {
                val = min(val, dp[r][k] + dp[k + 1][c] + v[r]*v[k + 1]*v[c + 1]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }
    return dp[0][n - 1];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        cout << mcm(v, 0, n - 2) << endl;
        // cout << mcmTD(v, 0, n - 2) << endl;
        // cout << mcmBU(v) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Mixtures (uses same concept as MCM)--------------------------------------------------------
                        
                        // (try bottom_up)
                        // debug the code
                        
//Recursive
ll minSmoke(const vector<int>& v, int i, int j) {
    if(i >= j)
        return 0;

    ll ans = INT_MAX;
    rep(k, i, j - 1) {
        
        ll l = 0, r = 0;

        rep(x, i, k) {
            l += v[x];
            l %= 100;
        }
        
        rep(x, k + 1, j) {
            r += v[x];
            r %= 100;
        }

        ans = min(ans, minSmoke(v, i, k) + minSmoke(v, k + 1, j) + l*r);
    }
    return ans;
}

//top_Down_DP
ll dp[1004][1004];
ll minSmokeTD(const vector<int>& v, int i, int j) {
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    ll ans = INT_MAX;
    rep(k, i, j) {
        
        ll l = 0, r = 0;

        rep(x, i, k) {
            l += v[x];
            l %= 100;
        }
        
        rep(x, k + 1, j) {
            r += v[x];
            r %= 100;
        }

        ans = min(ans, minSmokeTD(v, i, k) + minSmokeTD(v, k + 1, j) + l*r);
    }
    return dp[i][j] = ans;
}

signed main() {
    
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);

        for(auto &x : v)    cin >> x;
        // cout << minSmoke(v, 0, n - 1) << endl;
        cout << minSmokeTD(v, 0, n - 1) << endl;
    }
    
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Valentine_Magic--------------------------------------------------------

// top_down
ll dp[5004][5004];
ll minDiff(const vector<ll>& b, ll i, const vector<ll>& g, ll j, ll n, ll m) {
    if(i == n)
        return 0;

    if(j == m)
        return INT_MAX;       // all girls hv been rejected

    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll op1 = abs(b[i] - g[j]) + minDiff(b, i + 1, g, j + 1, n, m);
    ll op2 = minDiff(b, i, g, j + 1, n, m);

    return dp[i][j] = min(op1, op2);
}

// bottom_up (idea taken from Love_Babbar)
ll minDiff_BU(const vector<ll>& b, ll i, const vector<ll>& g, ll j, ll n, ll m) {
    ll dp[n + 1][m + 1];
    memset(dp, -1, sizeof dp);

    for(int ii = 0; ii < n; ii++)
        dp[ii][m] = INT_MAX;
    
    for(int jj = 0; jj <= m; jj++)
        dp[n][jj] = 0;

    for(int jj = m - 1; jj >= 0; jj--) {
        for(int ii = 0; ii < n; ii++) {
            ll op1 = abs(b[ii] - g[jj]) + dp[ii + 1][jj + 1];
            ll op2 = dp[ii][jj + 1];
            dp[ii][jj] = min(op1, op2);
        }
    }

    return dp[0][0];
}


signed main() {
    
    int t = 1;
    cin >> t;
    while(t--) {
        memset(dp , -1, sizeof dp);
        ll n, m; cin >> n >> m;
        vector<ll> b(n), g(m);
        for(auto &x : b)    cin >> x;
        for(auto &x : g)    cin >> x;

        sort(b.begin(), b.end());
        sort(g.begin(), g.end());

        // cout << minDiff(b, 0, g, 0, n, m) << endl;
        cout << minDiff_BU(b, 0, g, 0, n, m) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

//                   try new approach (kartik's video)
//                                  |
//                                  V
/*---------------------------- Optimal_Game_Strategy -> (GAME DP) --------------------------------------------------------

// top_down DP
int dp[104][104];
int maxScore(const vector<int>& v, int i, int j) {

    if(i + 1 == j)
        return max(v[i], v[j]);

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int op1 = v[i] + min(maxScore(v, i + 2, j), maxScore(v, i + 1, j - 1));
    int op2 = v[j] + min(maxScore(v, i + 1, j - 1), maxScore(v, i, j - 2));

    return dp[i][j] = max(op1, op2);
}

// bottom_down DP
int maxScoreBU(const vector<int>& v, int i, int j) {
    int n = v.size();
    int dp[104][104] = {0};

    int r = 0, c = 1;
    while(c < n) {
        dp[r][c] = max(v[r], v[c]);
        r++, c++;
    }

    for(int x = 2; x < n; x++) {
        r = 0, c = x;
        while(c < n) {
            dp[r][c] = max(v[r] + min(dp[r + 2][c], dp[r + 1][c - 1]),
                           v[c] + min(dp[r][c - 2], dp[r + 1][c - 1]));
            r++, c++;
        }
    }
    
    return dp[0][n - 1];
}



signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        // cout << maxScore(v, 0, n - 1) << endl;
        cout << maxScoreBU(v, 0, n - 1) << endl;
    }
    
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Egg_Dropping_Problem--------------------------------------------------------

//recursive DP
int minAttempts(int f, int e) {
    if(e == 0 or f == 0)
        return 0;

    if(e == 1)
        return f;
    
    if(f == 1)
        return 1;
    
    int ans = INT_MAX;
    for(int x = 1; x <= f; x++) {
        int b = minAttempts(x - 1, e - 1);
        int s = minAttempts(f - x, e);
        ans = min(ans, max(b, s));
    }
    return ans + 1;
}

//top_down
int dp[1004][1004];
int minAttemptsTD(int f, int e) {
    if(e == 0 or f == 0)
        return 0;

    if(e == 1)
        return f;
    
    if(f == 1)
        return 1;
    
    if(dp[e][f] != -1)
        return dp[e][f];
    
    int ans = INT_MAX;
    for(int x = 1; x <= f; x++) {
        int b = minAttempts(x - 1, e - 1);
        int s = minAttempts(f - x, e);
        ans = min(ans, max(b, s));
    }
    return dp[e][f] = ans + 1;
}

//bottom_up_DP -------------------------(not complete)
int minAttemptsBU(int f, int e) {
    int dp[f + 1][e + 1];

    memset(dp, 0, sizeof dp);

    for(int i = 0; i <= f; f++) {
        dp[1][i] = i;
    }

    for(int i = 0; i <= e; i++ ){
        dp[i][1] = 1;
    }

    for(int i = 2; i <= e; i++) {
        for(int j = 2; j <= f; j++) {
            
        }
    }


}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    cin >> t;
    while(t--) {
        int f, e; cin >> f >> e;
        // cout << minAttempts(f, e) << endl;
        cout << minAttemptsTD(f, e) << endl;
    }
    
    return 0;
}


-------------------------------------------------------------------------------------*/

//                            DP on Strings
//                                  |
//                                  |
//                                  V
/*-----------------------------Longest_Common_Subsequence (LCS)--------------------------------------------------------

//Brute force -> generating all subsequences and then finding LCS
// void generateSub(vector<string>& sub, string s) {
//     rep(i, 0, s.size() - 1) {
//         int n = sub.size() - 1;
//         rep(j, 0, n) {
//             string t = sub[j] + s[i];
//             sub.pb(t);
//         }
//     }
// }

// signed main() {
    
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     // memset(dp, -1, sizeof dp);

//     int t = 1; 
//     cin >> t;
//     while(t--) {

//         string s1, s2; cin >> s1 >> s2;
//         vector<string> sub1, sub2;

//         sub1.pb("");
//         sub2.pb("");

//         generateSub(sub1, s1);
//         generateSub(sub2, s2);

//         string ans = "";
//         int mx = INT_MIN;
//         rep(i, 0, sub1.size() - 1) {
//             rep(j, 0, sub2.size() - 1) {
//                 if(sub1[i] == sub2[j]) {
//                     mx = max(mx, (int)sub1[i].size());
//                     if(mx == sub1[i].size())
//                         ans = sub1[i];
//                 }
//             }
//         }

//         cout << ans.size() << " " << ans << endl;
//     }
    // return 0;
// }

// top_down
int dp[1004][1004];
int LCS(const string &x, const string &y, int i, int j) {

    if(i == -1 or j == -1)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(x[i] == y[j])
        return dp[i][j] = 1 + LCS(x, y, i - 1, j - 1);

    int op1 = LCS(x, y, i - 1, j);
    int op2 = LCS(x, y, i, j - 1);

    return dp[i][j] = max(op1, op2);   
}

//bottom_up_DP
int LCS_BU(string &x, string &y, int n, int m) {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        // printing the LCS
        vector<char> ans;
        int i = n, j = m;
        while(i >= 0 and j >= 0) {
            if(dp[i][j] == dp[i - 1][j])
                i--;
            else if(dp[i][j] == dp[i][j - 1])
                j--;
            else
                ans. pb(x[i - 1]), i--, j--;

        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans)
            cout << x;
        cout << endl;

        return dp[n][m];
    }

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    cin >> t;
    while(t--) {
        string x, y; cin >> x >> y;
        // cout << LCS(x, y, x.size() - 1, y.size() - 1) << endl;
        cout << LCS_BU(x, y, x.length(), y.length()) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------K-Ordered_LCS--------------------------------------------------------

int dp[2008][2008][6];
ll k_LCS(const vll&a, int i, const vll&b, int j, int cnt, int k) {
    if (i >= a.size() or j >= b.size())
        return 0;

    if(dp[i][j][cnt] != -1)
        return dp[i][j][cnt];

    if(a[i] == b[j])
        return dp[i][j][cnt] = 1 + k_LCS(a, i + 1, b, j + 1, cnt, k);

    int op1 = INT_MIN;
    if(cnt < k)
        op1 = 1 + k_LCS(a,i + 1, b, j + 1, cnt + 1, k);
    
    int op2 = k_LCS(a, i, b, j + 1, cnt, k);
    int op3 = k_LCS(a, i + 1, b, j, cnt, k);

    ll ans = max(op1, max(op2, op3));
    return dp[i][j][cnt] = (ans == INT_MIN ? 0 : ans);
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        ll n, m, k; cin >> n >> m >> k;
        vll a(n), b(m);
        for(auto &x : a)    cin >> x;
        for(auto &x : b)    cin >> x;

        cout << k_LCS(a, 0, b, 0, 0, k) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------01_Knapsack -> (pick_not-pick) (Imp. concept)--------------------------------------------------------

// brute_force
int maxVal(const vector<pair<int, int>>& item, int i, int j, int& sum, int& cap) {
    if(i > j)
        return 0;

    //pick if possible
    int op1 = 0;
    if(cap >= item[i].ff) {

        sum += item[i].ss;
        cap -= item[i].ff;

        op1 = item[i].ss + maxVal(item, i + 1, j, sum, cap);

        sum -= item[i].ss;
        cap += item[i].ff;
    
    }
    //not pick
    int op2 = 0 + maxVal(item, i + 1, j, sum, cap);

    return max(op1, op2);
}

//top_down
int dp[1004][1004];
int maxVal_TD(const vector<pair<int, int>>& item, int i, int j) {
    if(i > item.size() - 1)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int op1 = 0;
    if(j - item[i].ff >= 0)
        op1 = item[i].ss + maxVal_TD(item, i + 1, j - item[i].ff);

    int op2 = maxVal_TD(item, i + 1, j);
    return dp[i][j] = max(op1, op2);
} 

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, cap; cin >> n >> cap;
        vector<pair<int, int>> item(n);
        for(auto &x : item)  cin >> x.ff;
        for(auto &x : item)  cin >> x.ss;
        int sum = 0;
        // cout << maxVal(item, 0, n - 1, sum, cap) << endl;
        cout << maxVal_TD(item, 0, cap) << endl;
    }
    return 0;
}

//bottom up
// int max_profit_BU(const vll& w, const vll& p, ll i, ll cap) {
//     int dp[sz(w) + 1][cap + 1];
//     memset(dp , 0, sizeof dp);

//     rrep(i, sz(w) - 1, 0) {
//         rrep(j, cap, 0) {
//             int pick = 0, not_pick = 0;
//             if(w[i] <= j)
//                 pick = p[i] + dp[i + 1][j - w[i]];
//             not_pick = dp[i + 1][j];
//             dp[i][j] = max(pick, not_pick);
//         }
//     }
    
//     rep(i, 0, sz(w)) {
//         rep(j, 0, cap) {
//             cout << dp[i][j] << "\t";
//         }
//         cout << endl;
//     } 

//     return dp[0][cap];   
    
// }

// int main()
// {
//     fastio();
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt", "w", stderr);
//     #endif

//     int _t; cin >> _t; while(_t--) {
//         ll n, k; cin >> n >> k;
//         vll w(n), p(n);

//         for(auto &x : w)    cin >> x;
//         for(auto &x : p)    cin >> x;

//         vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
//         cout << max_profit_BU(w, p, 0, k) << endl;
//     }

// }

//Testcase : bottom_up)
// 1
// 5 10
// 2 2 6 5 4
// 2 3 5 4 6

// ans -> 11

-------------------------------------------------------------------------------------*/

/*-----------------------------Edit_Distance--------------------------------------------------------

// recursive / top_down / memoisation
int dp[1004][1004];
int minSteps(string &x, string &y, int i, int j) {
    if(i < 0 and j < 0)
        return 0;
    
    if(i < 0)
        return j + 1;

    if(j < 0)
        return i + 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(x[i] == y[j])
        return dp[i][j] = minSteps(x, y, i - 1, j - 1);
    
    int op1 = 1 + minSteps(x, y, i - 1, j);           //insert
    int op2 = 1 + minSteps(x, y, i, j - 1);           //delete
    int op3 = 1 + minSteps(x, y, i - 1, j - 1);       //replace
    return dp[i][j] = min(op1, min(op2, op3));
}

// bottom_up / iteration / tabulation 
int minSteps_BU(string &x, string &y, int i, int j) {
    int dp[x.length() + 1][y.length() + 1];
    memset(dp , -1, sizeof dp);

    for(int k = 0; k <= y.length(); k++)
        dp[0][k] = k;

    for(int k = 0; k <= x.length(); k++)
        dp[k][0] = k;

    for(int i = 1; i <= x.length(); i++) {
        for(int j = 1; j <= y.length(); j++) {
            
            if(x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            int op1 = 1 + dp[i - 1][j];           //insert
            int op2 = 1 + dp[i][j - 1];           //delete
            int op3 = 1 + dp[i - 1][j - 1];       //replace
            dp[i][j] = min(op1, min(op2, op3));
        }
    }
    return dp[x.length()][y.length()];
}


signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        // cout << minSteps(a, b, a.size() - 1, b.size() - 1) << endl;
        cout << minSteps_BU(a, b, a.size(), b.size()) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Vivek_loves_array_game--------------------------------------------------------

int maxScore(const vector<int>& v, int i, int j, const vector<int>& pre) {
    if(i >= j)
        return 0;

    int sum = pre[j] - (i ? pre[i - 1] : 0);

    if(sum % 2)
        return 0;

    int ans = INT_MIN;
    int flag = 0;
    rep(k, i, j - 1) {
        if(pre[k] - (i ? pre[i - 1] : 0) == pre[j] - pre[k]) {
            int op1 = 1 + maxScore(v, i, k, pre);
            int op2 = 1 + maxScore(v, k + 1, j, pre);
            ans = max(op1, op2);
            flag = 1;
            break;
        }
    }

    return (flag ? ans : 0);
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(dp, -1, sizeof dp);

    int t = 1; 
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;

        vector<int> pre(n);
        rep(i, 0, n - 1) {
            if(i == 0)  pre[i] = v[i];
            else    pre[i] = pre[i - 1] + v[i]; 
        }
        
        cout << maxScore(v, 0, n - 1, pre) << endl;
    }
    return 0;
}

// -------------------------------------------------------------------------------------*/

/*-----------------------------0N-Knapsack_problem--------------------------------------------------------

int dp[1004][1004];
int knapsack(const vector<int>& val, const vector<int>& wt, int s, int cap) {
    if(s >= val.size())
        return 0;

    if(dp[s][cap] != -1)
        return dp[s][cap];

    int op1 = 0;
    if(cap - wt[s] >= 0)
        op1 = val[s] + knapsack(val, wt, s, cap - wt[s]);
    
    int op2 = knapsack(val, wt, s + 1, cap);
    return dp[s][cap] = max(op1, op2);
}

                                // find the error
int bottomup(const vector<int>& val, const vector<int>& wt ,int i, const int cap) {
    int dp[1004][1004];
    int n = val.size();
    memset(dp, 0 ,sizeof dp);

    rrep(i, n - 1, 0) {
        rep(j, 1, cap) {
            int op1 = 0;
            if(j - wt[i] >= 0)
                op1 = val[i] + dp[i][j - wt[i]];

            int op2 = dp[i + 1][j];
            dp[i][j] = max(op1, op2);
        }
    }
    return dp[0][cap];
}


signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> wt(n), val(n);
        for(auto &x : wt)   cin >> x;
        for(auto &x : val)   cin >> x;

        // cout  << knapsack(val, wt, 0, k) << endl;
        cout  << bottomup(val, wt, 0, k) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Colourful_knapsack_problem--------------------------------------------------------

int dp[1004][1004];
int colourful_knapsack(const vector<vector<int>>& v, int i, int j) {
    
    // base case
    if(i > v.size() - 1)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = -1;
    for(int k = 0; k < v[i].size(); k++) {

        int op1 = -1;
        if(j - v[i][k] >= 0) {
            int poss = colourful_knapsack(v, i + 1, j - v[i][k]);
            if(poss == -1)
                continue;
            op1 = v[i][k] + poss;
        }
        ans = max(ans, op1);
    }

    return dp[i][j] = ans;
}


signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, m, cap; cin >> n >> m >> cap;
        vector<int> a(n);
        for(auto &x : a)    cin >> x;

        vector<vector<int>> v(m + 1);
        rep(i, 0, n - 1) {
            int x; cin >> x;
            v[x].pb(a[i]);
        }

        int ans = colourful_knapsack(v, 1, cap);
        if(ans == -1)
            cout << -1 << endl;
        else
            cout << cap - ans << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

//                                Grid_DP
//                                   |
//                                   |
//                                   V
/*-----------------------------Min_cost_path_in_a_grid-----------------------------------------------------------

int dp[1004][1004];
int minCost(const vector<vector<int>>& v, int i, int j) {
    if(i == v.size() - 1 and j == v[0].size() - 1)
        return v[i][j];

    if(dp[i][j] != -1)
        return dp[i][j];

    int r = INT_MAX, d = INT_MAX;
    if(i + 1 < v.size())
        d = v[i][j] + minCost(v, i + 1, j);
        
    if(j + 1 < v[0].size())
        r = v[i][j] + minCost(v, i, j + 1);

    return dp[i][j] = min(r, d);
}

int minCost_BU(const vector<vector<int>>& v, int i, int j, int n, int m) {
    
    int dp[n][m];
    memset(dp, -1, sizeof dp);

    rrep(x, n - 1, 0) {
        rrep(y, m - 1, 0) {
            if(x == n - 1 and y == m - 1) {
                dp[x][y] = v[x][y];
                continue;
            }

            int r = INT_MAX, d = INT_MAX;
            if(x + 1 < n)
                d = v[x][y] + dp[x + 1][y];

            if(y + 1 < m)
                r = v[x][y] + dp[x][y + 1];

            dp[x][y] = min(r, d);
        } 
    }
    return dp[0][0];
}

//try coding iterative dp in CB way -> easier to code

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        rep(i, 0, n - 1) {
            rep(j , 0, m - 1) {
                cin >> v[i][j];
            }
        }
        cout << minCost(v, 0, 0) << endl;
        // cout << minCost_BU(v, 0, 0, n, m) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Ways_to_reach_destination (Rat-version)--------------------------------------------------------

int dp[1004][1004];
int ways(int i, int j, int n, int m) {
    if(i == n - 1 and j == m - 1)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = 0, down = 0;
    if(j + 1 < m)
        right = ways(i, j + 1, n, m);
    if(i + 1 < n) 
        down = ways(i + 1, j, n, m);

    return dp[i][j] = right + down;
}

int ways_BU(int i, int j, int n, int m) {
    int dp[n][m];
    memset(dp, -1, sizeof dp);
    
    rrep(x, n - 1, 0) {
        rrep(y, m - 1, 0) {
            if(x == n - 1 and y == m - 1) {
                dp[x][y] = 1;
                continue;
            }

            int right = 0, down = 0;
            if(y + 1 < m)
                right = dp[x][y + 1];
            if(x + 1 < n) 
                down = dp[x + 1][y];

            dp[x][y] = right + down;
        }
    }
    return dp[0][0];
}

int ways_BU_1(int i, int j, int n, int m) {
    int dp[n][m];
    memset(dp, -1, sizeof dp);
    
    rep(x, 0, n - 1) {
        rep(y, 0, m - 1) {
            if(x == 0 or y == 0) {
                dp[x][y] = 1;
                continue;
            }

            int right = 0, up = 0;
            if(y - 1 >= 0)
                right = dp[x][y - 1];
            if(x - 1 >= 0) 
                up = dp[x - 1][y];

            dp[x][y] = right + up;
        }
    }
    return dp[n - 1][m - 1];
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        // cout << ways(0, 0, n, m) << endl;
        // cout << ways_BU(0, 0, n, m) << endl;
        cout << ways_BU_1(0, 0, n, m) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Ways_to_reach_destination (Elephant-version)--------------------------------------------------------

int dp[1004][1004];
int ways(int i, int j, int n, int m) {
    if(i == n - 1 and j == m - 1)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int k = 1;
    int ans = 0;
    while(i + k < n) {
        ans += ways(i + k, j, n, m);
        k++;
    }
    k = 1;
    while(j + k < m) {
        ans += ways(i, j + k, n, m);
        k++;
    }
    return dp[i][j] = ans;
}

int ways_BU(int i, int j, int n, int m) {
    int dp[n][m];
    rrep(x, n - 1, 0) {
        rrep(y, m - 1, 0) {
            if(x == n - 1 and y == m - 1) {
                dp[x][y] = 1;
                continue;
            }

            int k = 1;
            int ans = 0;
            while(x + k < n) {
                ans += dp[x + k][y];
                k++;
            }
            k = 1;
            while(y + k < m) {
                ans += dp[x][y + k];
                k++;
            }
            dp[x][y] = ans;
        }
    }
    return dp[0][0];
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        // cout << ways(0, 0, n, m) << endl;
        cout << ways_BU(0, 0, n, m) << endl;
        // cout << ways_BU_1(0, 0, n, m) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Robot_paths--------------------------------------------------------

ll dp[1004][1004];
int ways(int i, int j, int n, int m) {
    if(i == n and j == m) {
        if(dp[i][j] != 0)
            return 1;
        else    
            return 0;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    ll ans = 0;
    if(j + 1 <= m)
        ans = ((ans % MOD) + (ways(i ,j + 1, n ,m) % MOD)) % MOD;
    
    if(i + 1 <= n)
        ans = ((ans % MOD) + (ways(i + 1 ,j, n ,m) % MOD)) % MOD;

    return dp[i][j] = ans;
}

int ways_BU(int i, int j, int n, int m) {
    for(int y = m; y >= 1; y--) {
        for(int x = n; x >= 1; x--) {
            if(x == n and y == m) {
                if(dp[x][y] != 0)
                    dp[x][y] = 1;
                else    
                    dp[x][y] = 0;
                continue;
            }

            if(dp[x][y] == 0)
                continue;

            ll ans = 0;
            if(y + 1 <= m)
                ans = ((ans % MOD) + (dp[x][y + 1] % MOD)) % MOD;

            if(x + 1 <= n)
                ans = ((ans % MOD) + (dp[x + 1][y] % MOD)) % MOD;

            dp[x][y] = ans;
        }
    }
    return dp[1][1];
}



signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        while(k--) {
            int i, j; cin >> i >> j;
            dp[i][j] = 0LL;
        }
        // cout << ways(1, 1, n, m) << endl;

        cout << ways_BU(1, 1, n, m) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Gold_Grid (Uses 2D Prefix sum as DP)--------------------------------------------------------
const int N = 1e3 + 7;
int pre[N][N];

int sum(int a, int b, int c, int d) {
    return pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1];
}

ll minCoins(const vector<vector<int>>& grid, int i ,int j, int n) {
    int p1 = sum(1, 1, i, j);
    int p2 = sum(1, j + 1, i, n);
    int p3 = sum(i + 1, 1, n, j);
    int p4 = sum(i + 1, j + 1, n, n);
    return min(p1, min(p2, min(p3, p4)));
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
        int i, j;
        while(m--) {
            cin >> i >> j;
            grid[i][j] = 1;
        }
        rep(i, 1, n) {
            rep(j, 1, n) {
                pre[i][j] = grid[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        ll ans = INT_MIN;
        rep(i, 1, n - 1) {
            rep(j, 1, n - 1) {
                ans = max(ans, minCoins(grid, i, j, n));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Maximum_sum_rectangle-----------------------------------------------------------

//Using 2D Prefix-Sum

// const int N = 15;
// int pre[N][N]; 

// signed main() {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     // memset(dp, -1, sizeof dp);

//     int t = 1; 
//     cin >> t;
//     while(t--)  {
//         int n, m; cin >> n >> m;
//         vector<vector<int>> v(n + 1, vector<int>(m + 1));
//         rep(i, 1, n) {
//             rep(j ,1, m) {
//                 cin >> v[i][j];
//             }
//         }
//         //calc. pre sum
//         rep(i, 1, n) {
//             rep(j, 1, m) {
//                 pre[i][j] = v[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
//             }
//         }

//         int ans = INT_MIN;
//         rep(a, 1, n) {
//             rep(b, 1, m) {
//                 //v[i][j] -> (a, b)
//                 rep(c, a, n) {
//                     rep(d, b, m) {
//                         // v[x][y] -> (c, d)
//                         ans = max(ans, pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1]);
//                     }
//                 }
//             }
//         }
//         cout << ans << endl;
//     }  
//     return 0;
// }


// Using 1D-Kadane's Algorithm

int kadane(const vector<int>& v, int n) {
    int mx = INT_MIN;
    int sum = 0;
    rep(i, 0, n - 1) {
        sum += v[i];
        mx = max(mx, sum);
        if(sum < 0) sum = 0;
    }
    return mx;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(dp, -1, sizeof dp);

    int t = 1; 
    cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        rep(i, 0, n - 1) {
            rep(j , 0, m - 1) {
                cin >> v[i][j];
            }
        }

        int ans = INT_MIN;
        vector<int> col(n);
        rep(i, 0, m - 1) {
            rep(j, i, m - 1) {
                rep(k, 0, n - 1) {
                    col[k] += v[k][j];
                }
                ans = max(ans, kadane(col, n));
            }
            rep(k, 0, n - 1) col[k] = 0;
        }
        cout << ans << endl;
        
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Flood_Fill--------------------------------------------------------

int dp[5004][5004];
int fill(const vector<int>& v, int i, int j) {
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(v[i] == v[j])
        return dp[i][j] = 1 + fill(v, i + 1, j - 1);

    return dp[i][j] = 1 + min(fill(v, i + 1, j), fill(v, i, j - 1));
}

//int dp[5004][5004]; -> using dp[][] of prev,. method (why -> see common errors (1))
int fill_BU(const vector<int>& v) {
    int n = v.size();
    memset(dp ,0, sizeof dp);

    for(int x = 1; x < n; x++) {
        int r = 0, c = x;
        while(r < n and c < n) {
            if(v[r] == v[c])
                dp[r][c] = 1 + dp[r + 1][c - 1];
            else
                dp[r][c] = 1 + min(dp[r + 1][c], dp[r][c - 1]);
            r++, c++;
        }
    }

    return dp[0][v.size() - 1];
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n), ans;
        for(auto &x : v)    cin >> x;

        ans.pb(v[0]);
        rep(i, 1, n - 1) {
            if(v[i] != ans.back())
                ans.pb(v[i]);
        }
        
        // cout << fill(ans, 0, ans.size() - 1) << endl;
        cout << fill_BU(ans) << endl;
    }
    return 0;
}

// -------------------------------------------------------------------------------------*/

//                       Longest_Increasing_Subsequence
//                                    |
//                                    |
//                                    V
/*-----------------------------Box_Stacking_Problem-------------------------------------------------------

// must try with LIS after learning LIS (Love_Babbar) 

struct box {
    int l, w, h;
};

int dp[113][3];
int maxHeight(const vector<box>& v, int prev_box, int orient) {

    // no base case -> as pseudo base-case is present in for(....)loop.

    if(dp[prev_box][orient] != -1)
        return dp[prev_box][orient];

    int prev_l = 0, prev_w = 0, prev_h = 0;
    if(orient == 0) {
        prev_l = v[prev_box].l;
        prev_w = v[prev_box].w;
        prev_h = v[prev_box].h;
    }
    else if(orient == 1) {
        prev_l = v[prev_box].w;
        prev_w = v[prev_box].h;
        prev_h = v[prev_box].l;   
    }
    else {
        prev_l = v[prev_box].h;
        prev_w = v[prev_box].l;
        prev_h = v[prev_box].w;   
    }

    int ans = INT_MIN;
    for(int i = 1; i < v.size(); i++) {
        //trying orient = 0 for box v[i]
        if((v[i].l < prev_l and v[i].w < prev_w) or (v[i].w < prev_l and v[i].l < prev_w))
            ans = max(ans, v[i].h + maxHeight(v, i, 0));
        //trying orient = 1 for box v[i]
        if((v[i].w < prev_l and v[i].h < prev_w) or (v[i].h < prev_l and v[i].w < prev_w))
            ans = max(ans, v[i].l + maxHeight(v, i, 1));
        //trying orient = 2 for box v[i]
        if((v[i].h < prev_l and v[i].l < prev_w) or (v[i].l < prev_l and v[i].h < prev_w))
            ans = max(ans, v[i].w + maxHeight(v, i, 2));
    }
    if(ans == INT_MIN)  ans = 0;
    return dp[prev_box][orient] = ans;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1; 
    cin >> t;
    while(t--) {
        int n; cin >> n;
        memset(dp, -1, sizeof dp);
        vector<box> v(n + 1);
        v[0].l = 100001;
        v[0].w = 100001;
        v[0].h = 100001;
        rep(i, 1, n) {
            cin >> v[i].h >> v[i].w >> v[i].l;
        }        
        cout << maxHeight(v, 0, 0) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Wildcard_Pattern_Matching---------------------------------------------------------

int dp[1004][1004];
bool isMatching(const string& s, int n, const string& p, int m, int i, int j) {
    if(i > n - 1 and j > m - 1)
        return 1;

    if(i < n and j > m - 1)
        return 0;

    if(i > n - 1 and j < m) {
        for(int k = j; k < m; k++) {
            if(p[k] != '*')
                return 0;
        }
        return 1;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == p[j] or p[j] == '?')
        return dp[i][j] = isMatching(s, n, p, m, i + 1, j + 1);
    if(p[j] == '*') {
        bool op1 = 0, op2 = 0;
        op1 = isMatching(s, n, p, m, i, j + 1);
        op2 = isMatching(s, n, p, m, i + 1, j); 
        return dp[i][j] = (op1 || op2);

    }
    return dp[i][j] = 0;
}

bool solveTab(string &s, int n, string &p, int m, int i, int j) {
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);

    //initialising base cases
    dp[n][m] = 1;

    rep(j, 0, m - 1) {
        dp[n][j] = 1;
        rep(k, j, m - 1) {
            if(p[k] != '*') {
                dp[n][j] = 0;
                break;
            }
        }
    }
    //done

    rrep(j, m - 1, 0) {
        rrep(i, n - 1, 0) {
            if(s[i] == p[j] or p[j] == '?') {
                dp[i][j] = dp[i + 1][j + 1];
                continue;
            }
            if(p[j] == '*') {
                bool op1 = 0, op2 = 0;
                op1 = dp[i][j + 1];
                op2 = dp[i + 1][j]; 
                dp[i][j] = (op1 || op2);
                continue;
            }
            dp[i][j] = 0;
        }
    }
    return dp[0][0];
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        string s, p;
        cin >> s >> p;
        // cout << isMatching(s, s.size(), p, p.size(), 0, 0) << endl;
        cout << solveTab(s, s.size(), p, p.size(), 0, 0) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Subset_sum_easy--------------------------------------------------------

int sum = 0;
bool Subsetsumzero(const vector<int>& v, int i, int cnt) {
    if(cnt != 0 and sum == 0)
        return 1;

    if(i >= v.size())
        return 0;

    //pick
    sum += v[i];
    bool op1 = Subsetsumzero(v, i + 1, cnt + 1);

    //backtracking
    sum -= v[i];

    // not pick
    bool op2 = Subsetsumzero(v, i + 1, cnt);

    return (op1 or op2) ? 1 : 0;
}

void solve()
{
    ll n; cin >> n;
    vector<int> v(n);
    for(auto &x : v)    cin >> x;
    cout << (Subsetsumzero(v, 0, 0) ? "Yes" : "No") << endl;
}

int main()
{

    // memset(dp, -1, sizeof dp);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Subset_Sum_target-----------------------------------------------------------

int dp[1000][10005];
bool Sumtotarget(const vector<int>& v, int i, int sum, int t) {
    if(sum == t)
        return 1;

    if(i >= v.size())
        return 0;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    bool op1 = Sumtotarget(v, i + 1, sum + v[i], t);
    bool op2 = Sumtotarget(v, i + 1, sum, t);
    return dp[i][sum] = (op1 or op2);
}


signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, t; cin >> n >> t;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        cout << (Sumtotarget(v, 0, 0, t) ? "Yes" : "No") << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Square_Painting--------------------------------------------------------

const int N = 2000;
vector<vector<int>> prer(N, vector<int>(N));
vector<vector<int>> prec(N, vector<int>(N));

int count(const vector<vector<int>>& v, int i, int j, int k) {
    
    int ans = 0;
    int n = v.size();
    rep(y, j, j + k - 1) {
        int up = (i - 1 >= 0 ? prec[i - 1][y] : 0);
        int down = prec[n - 1][y] - prec[i + k - 1][y];
        if(up + down + k == n) ans++;
    }

    rep(x, i, i + k - 1) {
        int l = (j - 1 >= 0 ? prer[x][j - 1] : 0);
        int r = prer[x][n - 1] - prer[x][j + k - 1];
        if(l + r + k == n) ans++;
    }
    return ans;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(n, 0));
        rep(i, 0, n - 1) {
            rep(j , 0, n - 1) {
                char x; cin >> x;
                if(x == 'W') v[i][j] = 1;
            }
        }

        rep(i, 0, n - 1) {
            int sum = 0;
            rep(j, 0, n - 1) {
                sum += v[i][j];
                prer[i][j] = sum;
            }
        }
    
        rep(j, 0, n - 1) {
            int sum = 0;
            rep(i, 0, n - 1) {
                sum += v[i][j];
                prec[i][j] = sum;
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                ans = max(ans, count(v, i, j, k));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Circular_Merging--------------------------------------------------------

const int N = 1000;
vector<ll> pre(N, 0);

ll sum(ll i, ll j) {
    return pre[j] - (i - 1 >= 0 ? pre[i - 1] : 0);
}

ll dp[1004][1004];
ll minPenalty(const vector<ll>& v, ll i, ll j) {
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    ll ans = 1e18;
    for(ll k = i; k < j; k++) {
        ans = min(ans, minPenalty(v, i, k) + minPenalty(v, k + 1, j) + sum(i, k) + sum(k + 1, j));
    }
    return dp[i][j] = ans;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> v(n);
        for(auto &x : v)    cin >> x;
        rep(i, 0, n - 2) {
            v.pb(v[i]);
        }

        ll sum = 0;
        rep(i, 0, v.size() - 1) {
            sum += v[i];
            pre[i] = sum;
        }

        memset(dp, -1, sizeof dp);

        ll ans = 1e18;
        rep(i, 0, n - 1) {
            ans = min(ans, minPenalty(v, i, i + n - 1));
        }
        cout << ans << endl;
    }
    return 0;
}

// -------------------------------------------------------------------------------------*/

/*-----------------------------All_Ones_in_a_Rectangle--------------------------------------------------------

//approach 1
int pre[1004][1004] = {0};

int sum(int a, int b, int c, int d) {
    return pre[c][d] - pre[c][b - 1] - pre[a - 1][d] + pre[a - 1][b - 1];
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n + 1, vector<int>(m + 1));
        rep(i, 1, n) {
            rep(j, 1, m) {
                cin >> v[i][j];
            }
        }

        // filling pre[][]
        rep(i, 1, n) {
            rep(j, 1, m) {
                pre[i][j] = v[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
            }
        }

        int ans = 0;
        int len;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int a = i, b = j, c = i, d = j;
                while(c <= n and d <= m) {
                    
                    int k = sum(a, b, c, d);
                    if(k == (c - a + 1)*(c - a + 1)) {
                        ans = max(ans, k);
                        if(ans == k) {
                            len = (c - a + 1);
                        }
                    }
                    else 
                        break;
                    c++, d++;
                }
            }
        }
        cout << len << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Divisible_Patterns-------------------------------------------------------------

int dp[10004][2520 + 1];
int ways(const vector<int> &v, int i, int curr) {
    if(i >= v.size()) {
        return (curr == 0 ? 1 : 0);
    }

    if(dp[i][curr] != -1)
        return dp[i][curr];

    // learning at below line -> writing op1 = ways(v, i + 1, curr * v[i]) -> increases dp[][] size
    int op1 = ways(v, i + 1, (curr * v[i]) % 2520);

    int op2 = ways(v, i + 1, curr);

    return dp[i][curr] = ((op1 % MOD) + (op2 % MOD)) % MOD;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1; 
    // cin >> t;
    while(t--) {
        string p, s; cin >> p >> s;
        s = " " + s;
        vector<int> v;
        rep(i, 1, (s.size() - 1) - (p.size() - 1)) {
            if(s.substr(i, p.size()) == p)
                v.pb(i);
        }
        
        cout << ways(v, 0, 1) << endl;

    }  
    return 0;
}

-------------------------------------------------------------------------------------*/

/*-----------------------------Longest_Increasing_Subsequence--------------------------------------------------------


//Idea -> dp[i] stores the length of LIS which ends at v[i] 
int LIS_BU(const vector<int>& v) {
    int n = v.size();
    int dp[n];

    rep(i, 0, n - 1) {
        dp[i] = 1;
        rep(j, 0, i - 1) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int mx = 1;
    for(auto x : dp) {
        mx = max(mx, x);
    }
    return mx;
}

// naive dp[][] solution  ->  gives Runtime error if n = 10^5
int dp[1005][1005];
int LIS(const vector<int>& v, int i, int prev) {
    if(i >= v.size())
        return 0;

    if(dp[i][prev + 1] != -1)   // why, [prev + 1] --> becoz, -1 can't be index of arr[] 
        return dp[i][prev];

    int op1 = 0;
    if(prev == -1 or v[i] > v[prev])
        op1 = 1 + LIS(v, i + 1, i);          // pick 
    int op2 = LIS(v, i + 1, prev);           //not pick
    
    return dp[i][prev + 1] = max(op1, op2);
}

// Idea : dp[i] stores the "smallest" element at which LIS of length 'i' ends
// dp[] has LIS
int LIS_to_be_Bin(const vector<int>& v) {
    int n = v.size();
    int dp[n + 1];

    dp[0] = INT_MIN;
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    // finding smallest element in the arr. for  'ith' position in the LIS
    for(int i = 0; i < n; i++) {                 // i -> v[]
        for(int pos = 0; pos <= n; pos++) {
            if(dp[pos] < v[i] and v[i] < dp[pos + 1]) {
                dp[pos + 1] = v[i];
            }
        }
    }
    rrep(i, n, 0) {
        if(dp[i] != INT_MAX)
            return i;
    }
}

//optimising previous code with binary search on dp[] as it will always be sorted
// dp[] has LIS
int LIS_Bin(const vector<int>& v) {
    int n = v.size();
    vector<int> dp(n + 1);

    dp[0] = INT_MIN;
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    // finding smallest element in the arr. for  'ith' position in the LIS
    for(int i = 0; i < n; i++) {                 // i -> v[]

        // debug(dp);
        int pos = lower_bound(all(dp), v[i]) - dp.begin();
        dp[pos] = v[i];
        // debug(dp);
    }
    
    rrep(i, n, 1){
        if(dp[i] != INT_MAX)
            return i;
    }
}

signed main() {
    fastio();
    int t;  cin >> t;
    while(t--) {
        int n; cin >> n;

        memset(dp, -1, sizeof dp);

        vector<int> v(n);
        for(auto &x : v)    cin >> x;

        // cout << LIS(v, 0, -1) << endl;        // naive  2D - DP
        // cout << LIS_BU(v) << endl;
        
        // cout << LIS_to_be_Bin(v) << endl;
        cout << LIS_Bin(v) << endl;
    }
    return 0;
}

-------------------------------------------------------------------------------------*/

// /*-------------------------------------------------------------------------------------

signed main() {

    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    
    // memset(dp, -1, sizeof dp);
    
    int t = 1;  
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        vll v(n);
        for(auto &x : v)    cin >> x;

        debug(v);
    }
    return 0;
}

// -------------------------------------------------------------------------------------*/

// setup debugger
// read debug session (TLE)


// codeforces playing in casino
// codeforces see Dora and search code (stack learning)
// learn handling characters
// prod kadane's algo

