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

// Problem : https://atcoder.jp/contests/abc326/tasks/abc326_d

// Must see Vivek Bhaiya's solution ---> He beautifully used a string as a bitmask...
//                                  ---> for bitmask version of the Vivek Bhaiya's solution (see) commented code after main

int n;
string r, c;
int rmask;

string cur = "";
map<char, int> mp;

vector<string> perm[3];

void gen(int level) {
    if(level == n) {
        f(i, 0, n - 1) {
            if(cur[i] != '.') {
                perm[cur[i] - 'A'].pb(cur);
                break;
            }
        }
        re;
    }

    for(auto e: mp) {
        if(e.ss == 0)   continue;

        mp[e.ff]--;
        cur += e.ff;
        gen(level + 1);
        mp[e.ff]++;
        cur.ppb();
    }
}

vector<string> ans;
bool can_place(string& s, int row) {    
    f(i, 0, n - 1) {
        if(s[i]!='.' and ((rmask>>i)&1)==0 and s[i]!=c[i])    return 0;
    }
    return 1;
}

bool is_valid() {
    f(c, 0, n - 1) {
        set<char> st;
        f(r, 0, n - 1) {
            if(ans[r][c] != '.')    st.insert(ans[r][c]);
        } 
        if(st.size() != 3)  return 0;
    }
    return 1;
}

int makemove(string& str) {
    ans.pb(str);
    int prev_rmask = rmask;
    f(i, 0, n - 1) {
        if(str[i] != '.') rmask |= (1 << i);
    }
    return prev_rmask;
}

void revertmove(int prev_mask) {
    ans.ppb();
    rmask = prev_mask;
}

bool rec(int level) {

    // pr(level);
    // debvec(ans);

    if(level == n) {
        if(is_valid()) {
            cout << "Yes" << endl;
            for(auto e: ans) {
                cout << e << endl;
            }
            return 1;
        }
        return 0;
    }

    bool is_solved = 0;
    int firstch = r[level] - 'A';
    for(auto e: perm[firstch]) {
        if(can_place(e, level)) {
            int prev_mask = makemove(e);
            
            is_solved |= rec(level + 1);
            if(is_solved)   return 1;
            
            revertmove(prev_mask);
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> r >> c;
    mp['A'] = 1;
    mp['B'] = 1;
    mp['C'] = 1;
    mp['.'] = n - 3;

    gen(0);

    rmask = 0;
    bool ans = rec(0);
    if(!ans) {
        cout << "No" << endl;
    }
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
    solve();
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
int n;
string R, C;
vector<int> characters = {'A', 'B', 'C', '.'};
map<char, int> freq;
string s;
vector<string> all_positions[3];
vector<string> curr_sol, final_sol;
bool sol_found = false;
int all_done, none_done;


void generate(int level) {
    if (level == n) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '.') {
                all_positions[s[i] - 'A'].push_back(s);
                return;
            }
        }
        return;
    }
    for (auto &v : freq) {
        if (v.second > 0) {
            freq[v.first]--;
            s += v.first;
            generate(level + 1);
            s.pop_back();
            freq[v.first]++;
        }
    }
}


bool check(string row, int done) {
    for (int pos = 0; pos < n; pos++) {
        if (row[pos] != '.' && (done & (1 << pos)) == 0 && row[pos] != C[pos]) {
            return false;
        }
    }
    return true;
}


int newDone(int done, string row) {
    for (int pos = 0; pos < n; pos++) {
        if (row[pos] != '.') {
            done |= (1 << pos);
        }
    }
    return done;
}


bool is_valid(vector<string> sol) {
    for (int j = 0; j < n; j++) {
        set<char> st;
        for (int i = 0; i < n; i++) {
            if (sol[i][j] != '.') {
                st.insert(sol[i][j]);
            }
        }
        if (st.size() != 3) {
            return false;
        }
    }
    return true;
}


void rec(int level, int curr_done) {
    if (level == n) {
        if (curr_done == all_done && is_valid(curr_sol)) {
            sol_found = true;
            final_sol = curr_sol;
        }
        return;
    }
    if (sol_found) {
        return;
    }
    int first_ch = R[level] - 'A';
    for (auto &row : all_positions[first_ch]) {
        if (check(row, curr_done)) {
            curr_sol.push_back(row);
            rec(level + 1, newDone(curr_done, row));
            curr_sol.pop_back();
        }
    }
}


void solution() {
    cin >> n;
    cin >> R >> C;
    for (int i = 0; i < 3; i++) {
        freq[characters[i]] = 1;
    }
    freq['.'] = n - 3;
    generate(0);
    all_done = (1 << n) - 1;
    none_done = 0;
    rec(0, none_done);
    if (sol_found) {
        cout << "Yes" << endl;
        for (auto &v : final_sol) {
            cout << v << endl;
        }
    } else {
        cout << "No" << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
*/