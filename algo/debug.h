#include <bits/stdc++.h>
using namespace std;

//---- Debugger ---- //
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
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
//--------Mine Added (Inspiration : Vivek Gupta)--------- //
#define crndl cerr << "\n";
template <class T>ostream& operator <<(ostream& os, queue<T> p){ os << "[ "; while(!p.empty()) { os << p.front() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream &os, stack<T> p){ vector<T> v; while (!p.empty()) { v.push_back(p.top()); p.pop(); } reverse(all(v)); os << "[ " << v << "]"; return os; }
template <class T>ostream& operator <<(ostream &os, priority_queue<T> p){ os << "[ "; while (!p.empty()) { os << p.top() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream &os, priority_queue<T,vector<T>, greater<T>> p){ os << "[ "; while (!p.empty()) { os << p.top() << " "; p.pop(); } return os << "]"; }
template <class T>ostream& operator <<(ostream& os, const deque<T> &p){os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
//------------------------------------------------------- //



// // Old-Debugger

// using ll = long long;
// using ld = long double;
// using ull = unsigned long long;

// #define dbg(x...) cerr << #x << " "; _print(x); cerr << endl;
// #define debug(x,y...) cerr << #x << " -> "; _print(y); cerr << endl;
// #define crndl cerr << "\n";

// template <typename T> void _print (T t) { cerr << t; }
// void _print() {return;}

// template <class T> void _print(T a[], int n);  // ok
// template <class T> void _print(T a[], long long n);  // ok
// template <class T, class V> void _print(pair <T, V> p);  // ok
// template <class T> void _print(vector <T> v); // ok
// template <class T> void _print(set <T> v);  // ok
// template <class T, class V> void _print(unordered_map <T, V> v);  // ok
// template <class T, class V> void _print(map <T, V> v);  // ok
// template <class T> void _print(multiset <T> v);  //ok
// template <class T> void _print(queue <T> q);  // ok
// template <class T> void _print(stack <T> s);  // ok
// template <class T> void _print(priority_queue <T> pq);  // ok
// template <class T> void _print(priority_queue<T, vector<T>, greater<T>> pq);  // ok
// template <class T> void _print(deque <T> v);  // ok

// template <class T> void _print(T a[], int n) { cerr << "[ "; for(int i = 0; i < n; i++) { _print(a[i]); cerr << " "; } cerr << "]"; }
// template <class T> void _print(T a[], long long n) { cerr << "[ "; for(int i = 0; i < n; i++) { _print(a[i]); cerr << " "; } cerr << "]"; }
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(queue <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.front()); cerr << " "; q.pop();} cerr << "]";}
// template <class T> void _print(stack <T> s) {cerr << "[ "; stack<T> t; while (!s.empty()) {t.push(s.top()); s.pop();} while (!t.empty()) {_print(t.top()); cerr << " "; t.pop();} cerr << "]";}
// template <class T> void _print(priority_queue <T> pq) {cerr << "[ "; while (!pq.empty()) {_print(pq.top()); cerr << " "; pq.pop();} cerr << "]";}
// template <class T> void _print(priority_queue<T, vector<T>, greater<T>> pq) {cerr << "[ "; while (!pq.empty()) {_print(pq.top()); cerr << " "; pq.pop();} cerr << "]";}

// template <class T, class... V> void _print(T t, V... v) {_print(t); if(sizeof...(v)) {cerr<<", "; _print(v...);}}
// // template <class T> void _print(pbset<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// // template <class T> void _print(pbmultiset<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

