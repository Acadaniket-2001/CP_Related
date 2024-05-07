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
#include "algo/debug.h"
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
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------Heap Insertion and Deletion----------------------------

// ⭐ Implemented min-heap is 1-based indexed
//           i                       (i/2)         
//          / \          (OR)          |
//         /   \                       |
//       2i    2i + 1                 (i)

void insert(vll &v, ll x) {
    v.pb(x);
    int i = sz(v) - 1;

    while(i / 2 >= 1 and v[i] < v[i / 2]) { // v[i] < v[i/2] => Swap => cond. for min_heap
        swap(v[i], v[i / 2]);
        i /= 2;
    }
}

void heapify(vll &v, int i) {
    int LC = 2*i, RC = 2*i + 1;
    
    ll mn = v[i];
    if(LC < sz(v))  mn = min(mn, v[LC]);
    if(RC < sz(v))  mn = min(mn, v[RC]);

    if(mn == v[i])  return;
    else {
        if(LC < sz(v) and mn == v[LC])      swap(v[i], v[LC]), heapify(v, LC);
        else if(RC < sz(v) and mn == v[RC])     swap(v[i], v[RC]), heapify(v, RC);
    }
}

void remove(vll &v) {
    swap(v[1], v.back());
    v.ppb();
    heapify(v, 1);    // 1 -> heap's root_idx
}

int main()
{
    vll v(1); 

    int noe; cin >> noe;
    while(noe--) {
        ll x; cin >> x;
        insert(v, x);
    }

    int n = sz(v);
    f(i, 1, n - 1)  remove(v);
    return 0;
}

-------------------------------------------------------------------------------------*/

/*----------------------------Inplace heapify -> O(N.log(N))-------------------------

int main() {
    int n; cin >> n;
    vll v(n + 1); 
    f(i, 1, n)  cin >> v[i]; 

    //  ---> can be done in O(N) (Interview. Q -----> T.C. to build a heap from array = O(N))
    auto insert = [&](int i) {
        while(i / 2 >= 1 and v[i] < v[i / 2]) {
            swap(v[i], v[i / 2]);
            i /= 2;
        }
    };

    f(i, 1, n)    insert(i);
    cout << v;
    return 0;
}

-------------------------------------------------------------------------------------*/

/*----------------------------Inplace heapify -> O(N)--------------------------------

// See copy for T.C. proof

int main() {
    int n; cin >> n;
    vll v(n + 1); 
    f(i, 1, n)  cin >> v[i]; 

    //⭐ function<return type(parameter type)> ---> declaration is needed to write a recursive lambda function
    function<void(int)> heapify = [&](int i) {

        int LC = 2*i, RC = LC + 1;
        
        ll mn = v[i];
        if(LC <= n) mn = min(mn, v[LC]);
        if(RC <= n) mn = min(mn, v[RC]);

        if(mn == v[i])  return;
        else {
            if(LC <= n and mn == v[LC])     swap(v[i], v[LC]), heapify(LC);
            if(RC <= n and mn == v[RC])     swap(v[i], v[RC]), heapify(RC);
        }
    };

    rf(i, n / 2, 1)    heapify(i);
    
    cout << v;
    return 0;
}

-------------------------------------------------------------------------------------*/

/*----------------------------Inplace Heapsort---------------------------------------

void heapify(vll &v, int i, int end) {

    int LC = 2*i, RC = LC + 1;
    
    ll mx = v[i];
    if(LC <= end) mx = max(mx, v[LC]);
    if(RC <= end) mx = max(mx, v[RC]);

    if(mx == v[i])  return;
    else {
        if(LC <= end and mx == v[LC])     swap(v[i], v[LC]), heapify(v, LC, end);
        if(RC <= end and mx == v[RC])     swap(v[i], v[RC]), heapify(v, RC, end);
    }
}

void remove(vll &v, int end) {
    swap(v[1], v[end]);
    end--;
    heapify(v, 1, end);
    dbg(v);
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("C:/1_My_Data/CP_codes/io/Error.txt", "w", stderr);
        // freopen("C:/1_My_Data/CP_codes/io/Input.txt", "r", stdin);
        // freopen("C:/1_My_Data/CP_codes/io/Output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vll v(n + 1);
    f(i, 1, n)  cin >> v[i];

    // Building heap Inplace -> O(N)
    rf(i, n / 2, 1)    heapify(v, i, n);
    debug(heap, v) 

    // Deleting and storing inplace
    int end = n;
    f(i, 1, n) {
        remove(v, end);
        end--;
    }  
    // dbg(v)
    cout << v;
    return 0;
}

-------------------------------------------------------------------------------------*/

// /*----------------------------Applicative Problems------------------------------------

// Joining Ropes -> See CB video for question

int main() {

    int n; cin >> n;
    vector<int> ropes(n); cin >> ropes;

    p_q<int> pq;
    for(auto x : ropes) pq.push(-x);

    int cost = 0;
    while(pq.size() != 1) {
        int r1 = -pq.top();
        pq.pop();
        int r2 = -pq.top();
        pq.pop();

        cost += r1 + r2;
        pq.push(-r1 - r2);
    }

    cout << "Cost: " << cost << endl;
    return 0;
}

