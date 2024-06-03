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

/*-----------------------------------------------------------------------------------------------------------------
⭐Index: (STL Week) 
    
    Day 22: Deque, Indexed Set              (read AZ website) 
    
    Day 23: upper_bound, lower_bound        (read AZ website and notes made in class)
    
    Day 24: Balanced parenthesis -> depth concept ->    (this code and notes made in class)
    
    Day 25: (⭐Window Maintainance, sliding window) -> ⭐monotone_deque usage ->   (read website, this code, class notes)
    
    Day 26: ⭐counting subarrays with sum=X in O(nlogn), Game thoery proving game ideas (in short) ->   (this note for sum=X Ques.; notes made in class)
    
    Day 27: Running Mean, Variance, Median, Mode ->   (see running_mean_median_mode.cpp and notes made in class)
    
-----------------------------------------------------------------------------------------------------------------*/

/* ⭐ Balanced parenthesis (depth concept)------------------------------------
int main()
{
    // // version 1
    // string s; cin >> s;
    // bool is_bal = 1;
    // int depth = 0;

    // f(i, 0, sz(s) - 1) {
    //     if(s[i] == '(') depth++;
    //     else {
    //         depth--;
    //         is_bal &= (depth >= 0);
    //     }
    // }

    // is_bal  &= (depth == 0);
    // cout << (is_bal ? "Yes" : "No") << endl;


    // version 2
    string s; cin >> s;
    map<char, int> mp;
    mp['('] = 1;
    mp['['] = 2;
    mp['{'] = 3;
    mp['<'] = 4;
    mp[')'] = -1;
    mp[']'] = -2;
    mp['}'] = -3;
    mp['>'] = -4;

    stack<int> st;
    bool is_bal = 1;
    f(i, 0, sz(s) - 1) {
        int val = mp[s[i]];
        if(val > 0) {
            st.push(val);
        }
        else {
            if(!st.empty() and st.top() + val == 0) st.pop();
            else    is_bal = 0;
        }
    }

    if(st.empty() and is_bal)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    // mountain diagram for queries

    return 0;
}
  Balanced parenthesis------------------------------------------- */

// Heading: Subarray finding -> (V.V.Imp),  Sliding window
/* ⭐All min in a window of size k O(NlogK)-----------------------------------

// version 1: find max of all subarray of size k 
// version 2: find sum of all subarray of size k 
// version 3: find #distinct of all subarray of size k  --> Use Bag of algorithmic design(Algorithmic_design.cpp)
//   ....
//   ....

int main() {
    int n, k; cin >> n >> k;
    vll v(n); cin >> v;
    multiset<int> mst;

    // General code for maintaining window
    f(i, 0, n - 1) {                // O(N)
        mst.insert(v[i]);                                       // O(logK)
        if(i - k >= 0)  mst.erase(mst.find(v[i - k]));          // O(logK)

        // if(mst.size() == k) cout << *mst.begin() << " ";     // O(1)
        if(i - (k - 1) >= 0) cout << *mst.begin() << " ";       // O(1)
    } // O(NlogK)
}

    All min in a window of size k-----------------------------------*/

/* ⭐All min in a window of size k O(N)---------------------------------------

struct monotone_deque {
    deque<int> dq;

    void insert(int x) {
        while(dq.size() and dq.back() > x)  dq.ppb();   // ⚠️Beware!!!, do not write dq.back() >= x  => v: [ 1 2 1 2 ] gives WA
        dq.pb(x);    
    }

    void erase(int x) {
        if(dq.front() == x) 
            dq.pop_front();
    }

    int getmin() {
        return dq.front();
    }
};

int main() {

    int n, k; cin >> n >> k;
    vll v(n);   cin >> v;

    monotone_deque mt;

    f(i, 0, n - 1) {                                        //O(n)
        mt.insert(v[i]);                                    //O(1) -> amortised
        if(i - k >= 0)  mt.erase(v[i - k]);                 //O(1)
        if(i - (k-1) >= 0)  cout << mt.getmin() << " ";     //O(1)
    }  // O(n)
    return 0;
}

   ⭐All min in a window of size k-----------------------------------*/

// /*⭐Count and print subarrays wit sum = X--------------------------------

int main() {

    int n, x; cin >> n >> x;
    vll v(n);

    f(i, 0, n - 1) {
        cin >> v[i];
        if(i)   v[i] += v[i - 1];
    }

    map<int, vector<int>> mp;
    mp[0];
    f(j, 0, n - 1) {
        
        mp[v[j] - x].pb(j);
        mp[v[j]];
    }

    for(auto e: mp)
        cout << e.ff << " : " << e.ss; 

    return 0;
}





//   ⭐Count and print subarrays wit sum = X--------------------------------*/