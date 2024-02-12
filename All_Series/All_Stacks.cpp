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
#define re return
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif
// ganit

// // Problem : Reverse a stack using recursion.
// void insert_bottom(stack<int> &st, int n) {
//     if(st.empty()) {
//         st.push(n);
//         return;
//     }
//     int x = st.top();
//     st.pop();
//     insert_bottom(st, n);
//     st.push(x);
// }
// void reverse_rec(stack<int> & st) {
//     if(st.empty())
//         return;
//
//     int x = st.top();
//     st.pop();
//     reverse_rec(st);
//     insert_bottom(st, x);
// }

// // Problem : Reverse a stack using another single stack.
// void transfer(stack<int> &s1, stack<int> &s2, int n) {
//     f(i, 1, n) {
//         s2.push(s1.top());
//         s1.pop();
//     }
// }
// void reverseStack(stack<int> &s1) {
//     stack<int> s2;
//     int n = sz(s1);
//
//     f(i, 1, sz(s1)) {
//         int x = s1.top();
//         s1.pop();
//
//         transfer(s1, s2, n - i);   // s1 -> s2
//         s1.push(x);
//         transfer(s2, s1, n - i);   // s2 -> s1
//     }
// }
//
// void solve()
// {
//     ll n; cin >> n;
//     stack<int> st;
//     f(i, 0, n - 1) {
//         int x; cin >> x;
//         st.push(x);
//     }
//
//     reverseStack(st);
//  
//     reverse_rec(st);
//
//     while(!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }    
//     cout << endl;
// }
//
// int main()
// {
//     int _t; cin >> _t; while(_t--)
//     solve();
//     return 0;
// }

// // Problem : Balanced Parenthesis
// //         M1: CP method
// //         M2: Stack
//
// bool check(string s) {
//     stack<char> st;
//     for(auto x : s) {
//         if(x == '(')    st.push(x);
//         else if(x == ')') {
//             if(!st.empty() and st.top() == '(') st.pop();
//             else return 0;
//         }
//     }
//     return st.empty();
// }
// int main() {
//     int _t; cin >> _t; while(_t--) {
//         string s; cin >> s;
//         cout << (check(s) ? "yes" : "no") << endl;
//     }
//     return 0;
// }

// // Problem : Stock Span Problem (PGE -> Application)
//    See CB video at (05:40) for gist
//
// vll PGE(vector<ll> &v) {
//     vll ans;
//     stack<ll> st;
//
//     ans.pb(-1);
//     st.push(0);
//     f(i, 1, sz(v) - 1) {
//         while(!st.empty() and v[st.top()] <= v[i])  st.pop();
//         if(st.empty())  ans.pb(-1);
//         else ans.pb(st.top());
//         st.push(i);
//     }
//     return ans;
// }
//
// int main() {
//     int _t; cin >> _t; while(_t--) {
//         ll n; cin >> n;
//         vll v(n);
//         for(auto &x : v)    cin >> x;
//         vll pge = PGE(v);
//         dbg(pge);
//         f(i, 0, n - 1) {
//             pge[i] = i - pge[i];
//             cout << pge[i] << " \n"[i == n - 1];
//         }
//     }
//     return 0;
// }
//
// // i/p:
// // 1
// // 7
// // 100 80 60 70 60 75 185
// // o/p: 1 1 1 2 1 4 7

// // Problem : Max Area under Histogram (PGE and NGE -> Application)
//         M1: Brute Force   ->   O(n^2)
//             take two pointers i and j to get the width of the rectangle.
//             and min(v[i], v[i + 1], ... ,v[j]) is height.
//
//         M2: Divide and Conquer   ->   O(n.log(n))
//
//         M3: Stack   ->   O(n)
//             Idea is to find largest rectangle of each ht. in the array 
//
// vll PSE(vector<ll> &v) {
//     stack<ll> st;
//     vll ans;
//  
//     ans.pb(-1);
//     st.push(0);
//     f(i, 1, sz(v) - 1) {
//         while(!st.empty() and v[st.top()] >= v[i])  st.pop();
//         if(st.empty())  ans.pb(-1);
//         else ans.pb(st.top());
//         st.push(i);
//     }
//     return ans;
// }
//
// vll NSE(vector<ll> &v) {
//     stack<ll> st;
//     vll ans;
//     ll n = sz(v);
//
//     ans.pb(n);
//     st.push(n - 1);
//     rf(i, sz(v) - 2, 0) {
//         while(!st.empty() and v[st.top()] >= v[i])  st.pop();
//         if(st.empty())  ans.pb(n);
//         else ans.pb(st.top());
//         st.push(i);
//     }
//     reverse(all(ans));
//     return ans;
// }
//
// int main() {
//     int _t; cin >> _t; while(_t--) {
//         ll n; cin >> n;
//         vll v(n);
//         for(auto &x : v)    cin >> x;
//         vll pse = PSE(v);
//         vll nse = NSE(v);
//
//         dbg(pse)
//         dbg(nse)
//
//         ll mx_area = INT_MIN;
//         f(i, 0, n - 1) {
//             ll width = nse[i] - pse[i] - 1;
//             ll ht = v[i];
//             mx_area = max(mx_area, width * ht);
//         }
//         cout << mx_area << endl;
//     }
//     return 0;
// }
// // i/p: 
// // 1
// // 7
// // 6 2 5 4 5 1 6
// // o/p: 12
// // pse [ -1 -1 1 1 3 -1 5 ]
// // nse [ 1 5 3 5 5 7 7 ]

// // Problem : Min-Max Stack
//       M1: Maintinaing 1 min_stack and 1 max_stack and maintain
//           them after every insertion and deletion.
//           O(1) time and O(n) space
//
//       M2: O(1) time and [ O(1)space => Variable (Tricky) ]

/* M1-----------------------------------------------------------------------------
class min_max_Stack {
    private:
        vector<int> v, mn, mx;
  
    public: 
        int top() { return v.back(); }
        void push(int x) {
            v.pb(x);
            if(v.size() == 1) { mn.pb(x), mx.pb(x); }
            else {
                if(x < mn.back())   mn.pb(x);
                else    mn.pb(mn.back());

                if(x > mx.back())   mx.pb(x);
                else    mx.pb(mx.back());
            }
        }
        void pop() {
            v.ppb(), mx.ppb(), mn.ppb();
        }
        int get_min() { return mn.back(); }
        int get_max() { return mx.back(); }
        bool empty() { return (v.size() == 0);  }
        void print() {
            f(i, 0, sz(v) - 1) {
                cout << v[i] << " \n"[i == sz(v) - 1];
            }
            f(i, 0, sz(v) - 1) {
                cout << mn[i] << " \n"[i == sz(v) - 1];
            }
            f(i, 0, sz(v) - 1) {
                cout << mx[i] << " \n"[i == sz(v) - 1];
            }
        }
};

int main() {  
    min_max_Stack st;
    st.push(1);
    st.push(5);
    st.push(4);
    st.push(9);
    st.push(-1);
   
    st.print();
    cout << st.get_max() << endl;
    st.pop();
    cout << st.get_min() << endl;
    cout << st.get_max() << endl;
    st.pop();
    st.pop();
   
    cout << st.top() << endl;
    cout << st.get_max() << endl;
    return 0;
}
----------------------------------------------------------------------------------*/

/* M2-----------------------------------------------------------------------------
class min_Stack {
    private:
        vector<int> v;
        int mn;
  
    public: 
        int top() {
            if(!v.size())
                return INT_MIN;
            else if(v.back() < mn)
                return mn;
            else
                return v.back();
        }
        void push(int x) {
            if(!v.size()) {
                v.pb(x);
                mn = x;
            }
            else if(x < mn) {
                v.pb(2*x - mn);
                mn = x;
            }
            else    v.pb(x);
        }
        void pop() {
            if(!v.size())
                return;
            else if(v.back() < mn) {
                mn = 2*mn - v.back();
                v.ppb();
                return;
            }
            else {
                v.ppb();
                return;
            }
        }
        int get_min() {
            if(!v.size())
                return INT_MIN;
            return mn;
        }
        bool empty() { return (v.size() == 0);  }
};
int main() {
    min_Stack st;
    st.push(1);
    st.push(5);
    st.push(4);
    st.push(9);
    st.push(-1);
   
    st.pop();
    cout << st.get_min() << endl;
    st.pop();
    st.pop();
   
    cout << st.top() << endl;
    cout << st.get_min() << endl;
    st.pop();
    cout << st.get_min() << endl;
    st.pop();
    cout << st.get_min() << endl;
    st.pop();
    cout << st.get_min() << endl;
    st.push(50);
    cout << st.get_min() << endl;
    return 0;
}

------------------------------------------------------------------------------*/

/* Problem : Rain water Harvesting------------------------------------------------

//     Idea :  Water level above idx i depends on max elements
//             in subarray form indices [0...i-1] and [i+1...n-1]
//       ⚠️⚠️ NO notion of NGE or PGE ,here

int main() {
    ll n; cin >> n;
    vll v(n);
    for(auto &x : v)    cin >> x;
    vector<ll> maxl, maxr;

    ll mx = INT_MIN;
    f(i, 0, sz(v) - 1) {
        mx = max(mx, v[i]);
        maxl.pb(mx);
    }

    mx = INT_MIN;
    rf(i, sz(v) - 1, 0) {
        mx = max(mx, v[i]);
        maxr.pb(mx);
    }
    reverse(all(maxr));

    dbg(maxl)
    dbg(maxr)

    ll ans = 0;
    f(i, 1, sz(v) - 2) {
        ll x = min(maxl[i - 1], maxr[i + 1]) - v[i];
        if(x >= 0)  ans += x;
    }

    cout << ans << endl;
    return 0;
}
---------------------------------------------------------------------------------*/

/* Problem : Stack using 2 Queues-------------------------------------------------

//    Idea :  One Queue will always be empty in the implementation.
//            Always push the element in the non_empty Queue and 
//            during pop move (sz(Q) - 1) elements from non_empty Queue and
//            return the last ele. as popped element.

//    T.C. :  push(x), isEmpty() -> O(1)
//            pop(), top() -> O(N)

//           See CB video for better understanding...😊😊

int main() {
    



    return 0;
}

*/

// Expression Evaluation ---------------------------------------------------------------

/* Infix Evaluation -------------------------------------------------------------------

// ⭐ Feasible for humans but not for m/c => Use 2 stacks

int precedence(char ch) {
    if(ch == '+')   return 1;
    else if(ch == '-')   return 1;
    else if(ch == '*')   return 2;
    else   return 2;
}

int res(int v1, int v2, char operation) {
    if(operation == '+')    return (v1 + v2);
    else if (operation == '-')  return (v1 - v2);
    else if (operation == '*')  return (v1 * v2);
    else    return (v1 / v2);
}

int main() {
    
    string s; cin >> s;

    stack<int> num;
    stack<char> opr;

    f(i, 0, sz(s) - 1) {
        if(isdigit(s[i])) {    // s[i] -> operand
            num.push(s[i] - '0');
        }
        
        else if (s[i] == '(')   opr.push(s[i]);
        
        else if (s[i] == ')') {
            while(opr.size() and  opr.top() != '(') {
                char operation = opr.top();
                opr.pop();
                int v2 = num.top();
                num.pop();
                int v1 = num.top();
                num.pop();
                num.push(res(v1, v2, operation));
            }
            opr.pop();
        }
        
        else {    // s[i] -> operator
            while(opr.size() and opr.top() != '(' and precedence(opr.top()) >= precedence(s[i])) {
                char operation = opr.top();
                opr.pop();
                int v2 = num.top();
                num.pop();
                int v1 = num.top();
                num.pop();
                num.push(res(v1, v2, operation));
            }
            opr.push(s[i]);
        }   
    }

    while(opr.size()) {
        char operation = opr.top();
        opr.pop();
        int v2 = num.top();
        num.pop();
        int v1 = num.top();
        num.pop();
        num.push(res(v1, v2, operation));
    }
    cout << num.top() << endl;
    return 0;
}
-----------------------------------------------------------------------------------*/

/* Infix Conversion -------------------------------------------------------------------

// ⭐ Feasible for humans but not for m/c => Use 2 stacks

int precedence(char ch) {
    if(ch == '+')   return 1;
    else if(ch == '-')  return 1;
    else if(ch == '*')  return 2;
    else return 2;
}

void perform_opr(stack<string> &pre, stack<string> &post, stack<char> &opr) {
    char operation = opr.top(); opr.pop();
                
    string b = pre.top(); pre.pop();        // ⚠️ beware of order
    string a = pre.top(); pre.pop();
    string res = operation + a + b;
    pre.push(res);

    b = post.top(); post.pop();      // ⚠️ beware of order
    a = post.top(); post.pop();
    res = a + b + operation;
    post.push(res);
}

int main() {

    string s; cin >> s;
    stack<string> pre, post;
    stack<char> opr;

    f(i, 0, sz(s) - 1) {
        if(s[i] == '(') {
            opr.push(s[i]);
        }
        else if(s[i] == ')') {
            while(opr.size() and opr.top() != '(') {
                perform_opr(pre, post, opr);
            }
            opr.pop();
        }
        else if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
            while(opr.size() and opr.top() != '(' and precedence(opr.top()) >= precedence(s[i])) {
                perform_opr(pre, post, opr);
            }
            opr.push(s[i]);
        }
        else {
            pre.push(string(1, s[i]));
            post.push(string(1, s[i]));
        }
    }
    while(opr.size()) {
        perform_opr(pre, post, opr);    
    }
    cout << "Prefix -> " << pre.top() << endl;
    cout << "Postfix -> " << post.top() << endl;
    return 0;
}

-----------------------------------------------------------------------------------*/

/* Prefix Evaluation-------------------------------------------------------------------

// ⭐ Scan from R -> L

void perform_opr(stack<int> &val, char ch) {
    int a = val.top(); val.pop();
    int b = val.top(); val.pop();

    if(ch == '+')   val.push(a + b);
    else if(ch == '-')   val.push(a - b);
    else if(ch == '*')   val.push(a * b);
    else   val.push(a / b);
}

int main() {

    string s; cin >> s;

    stack<int> val;
    stack<string> in, post;

    rf(i, sz(s) - 1, 0) {
        if(isdigit(s[i]))   val.push(s[i] - '0');
        else    perform_opr(val, s[i]);
    }

    cout << "Value -> " << val.top() << endl;
    return 0;
}

---------------------------------------------------------------------------------------*/

/* Prefix Conversion ------------------------------------------------------------------

// ⭐ Scan from R -> L

void perform_opr(stack<string> &in, stack<string> &post, char ch) {
    string a = in.top(); in.pop();
    string b = in.top(); in.pop();
    string res = a + ch + b;
    in.push(res);
    
    a = post.top(); post.pop();
    b = post.top(); post.pop();
    res = a + b + ch;
    post.push(res);
}

int main() {

    string s; cin >> s;

    stack<string> in, post;

    rf(i, sz(s) - 1, 0) {
        if(isdigit(s[i])) {
            in.push(string(1, s[i]));
            post.push(string(1, s[i]));
        }
        else {
            perform_opr(in, post, s[i]);
        }
    }

    cout << "Infix -> " << in.top() << endl;
    cout << "Postfix -> " << post.top() << endl;
    return 0;
}

----------------------------------------------------------------------------------------*/

/* Postfix Evaluation -----------------------------------------------------------------

// ⭐ Scan from L -> R

void perform_opr(stack<int> &val, char ch) {
    int b = val.top(); val.pop();
    int a = val.top(); val.pop();

    if(ch == '+')   val.push(a + b);
    else if(ch == '-')   val.push(a - b);
    else if(ch == '*')   val.push(a * b);
    else   val.push(a / b);
}

int main() {

    string s; cin >> s;
    stack<int> val;

    f(i, 0, sz(s) - 1) {
        if(isdigit(s[i])) {
            val.push(s[i] - '0');
        }
        else {
            perform_opr(val, s[i]);
        }
    }
    
    cout << val.top() << endl;
    return 0;
}

-------------------------------------------------------------------------------------*/

/* Postfix Conversion -----------------------------------------------------------------

// ⭐ Scan from L -> R

void perform_opr(stack<string> &in, stack<string> &pre, char ch) {
    string b = in.top(); in.pop();
    string a = in.top(); in.pop();
    string res = a + ch + b;
    in.push(res);

    b = pre.top(); pre.pop();
    a = pre.top(); pre.pop();
    res = ch + a + b;
    pre.push(res);
}

int main() {

    string s; cin >> s;
    stack<string> in, pre;

    f(i, 0, sz(s) - 1) {
        if(isdigit(s[i])) {
            in.push(string(1, s[i]));
            pre.push(string(1, s[i]));
        }
        else {
            perform_opr(in, pre, s[i]);
        }
    }
    
    cout << "Infix -> " << in.top() << endl;
    cout << "Prefix -> " << pre.top() << endl;
    return 0;
}

-------------------------------------------------------------------------------------*/

