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
/*-------------------> Current Level <----------------------
2. Think all possibilities
3. Think greedy
4. Think sortings
5. Think constructive algorithms
1. ⭐ Think brute force
6. ⭐ Think implementation
7. ⭐ Think math
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// TIPs:
//      1. whenever trying to access a node, must check that it is not null     
//          E.g.: 
//                 if(root) cout << root -> data;
// 
//      2. When some parameter is to be calc. using parameter of Lsubtree and Rsubtree use bottom-up approach 
//         Post_order traversal.
//
//      3. 
//
//---------------------------------------------------------------------------------
//         3       lvl = 1
//        / \
//       /   \
//      4     5    lvl = 2
//       \   /
//        6 1      lvl = 3 = height of tree
//
//  3 4 -1 6 -1 -1 5 1 -1 -1 -1
//
//---------------------------------------------------------------------------------
//            
//         8
//        / \
//       /   \
//      10    3
//     / \     \
//    /   \     \
//   1     6     14
//        / \    /
//       9   7  13
//
//  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
       
class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* build() {
    int d; cin >> d;

    if(d == -1)
        return NULL;
    
    else {
        node * N = new node(d);
        N -> left = build();
        N -> right = build();
    }
}

// Preorder    // print inorder and postorder
void print(node * root) {
    if(root == NULL)    return;

    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
}

int height(node * root) {
    if(root == NULL)    return 0;

    int hl = height(root -> left);
    int hr = height(root -> right);
    return max(hl, hr) + 1;
}

// recursive method -> O(N^2)
void level_order(node * root, int h) {
    if(root == NULL)
        return;

    if(h == 1 and root != NULL)  {
        cout << root -> data << " ";
        re;
    }

    level_order(root -> left, h - 1);
    level_order(root -> right, h - 1);
}
// BFS method -> O(N)
// o/p: Nodes of all levels in one line
void level_order_BFS(node * root) {

    queue<node *> q;
    q.push(root);

    while(sz(q)) {
        auto x = q.front(); q.pop();
        
        if(!x)  continue;
        cout << x -> data << " ";
        q.push(x->left);
        q.push(x->right);
    }
}
// o/p: level wise -> one line has only one level of nodes
void BFS(node * root) {
    queue<node *> q;
    q.push(root), q.push(NULL);          // NULL: is pushed as a marker of end of a lvl, and not the NULL node, see line: 157

    while(!(q.size() == 1 and q.front() == NULL)) {
        auto x = q.front(); q.pop();
        if(x) {
            cout << x -> data << " ";
            if(x -> left)   q.push(x->left);
            if(x -> right)  q.push(x->right);
        }
        else {   // x = NULL  => all elem. of prev hv been entered in q. so, push a newline marker.
            cout << endl;
            q.push(NULL);
        }
    }
}

int count_nodes(node * root) {
    if(root == NULL)    return 0;
    return count_nodes(root -> left) + count_nodes(root -> right) + 1;
}

int sum_nodes(node * root) {
    if(root == NULL)    return 0;
    return sum_nodes(root -> left) + sum_nodes(root -> right) + root -> data;
}

// O(N^2)
int diameter(node * root) {

    if(root == NULL)    return 0;

    int mx = INT_MIN;
    // case 1
    if(root -> left)    mx = max(mx, diameter(root -> left));
    // case 2
    if(root -> right)    mx = max(mx, diameter(root -> right)); 
    // case 3
    mx = max(mx, height(root -> left) + height(root -> right));
    return mx;
} 
// O(N) --> since, left -> right -> root ===> post-order trav. / ⭐Bottom-up traversal
pair<int, int> diameterOpt(node * root) {    // {ht , dia}
    
    if(root == NULL)    return {0, 0};

    pair<int, int> LsubTree = {0, 0}, RsubTree = {0, 0};
    LsubTree = diameterOpt(root -> left);                                            // Left
    RsubTree = diameterOpt(root -> right);                                           // right

    int ht_Tree = max(LsubTree.ff, RsubTree.ff) + 1;                                 // root
    int dia_Tree = max(LsubTree.ff + RsubTree.ff, max(LsubTree.ss, RsubTree.ss));    // root
    return {ht_Tree, dia_Tree};
}

// Replace each node with the sum of all of its descendents
int sum_replace(node * root) {
    if(root == NULL)    return 0;

    if(root -> left == NULL and root -> right == NULL)  return root -> data;

    int Lsum = 0, Rsum = 0; 
    if(root -> left)    Lsum = sum_replace(root -> left);
    if(root -> right)    Rsum = sum_replace(root -> right);

    int temp = root -> data;
    root -> data = Lsum + Rsum;
    return root -> data + temp;
}

//---------------------------------AVL Tree---------------------------------------

// Do Bottom_up to avoid calc. height of each subtree....
pair<bool, int> check_AVL(node * root) {    // {bool, height}
    if(!root)   return {1, 0};

    pair<bool, int> L = {1, 0}, R = {1, 0};

    if(root -> left)    L = check_AVL(root -> left);
    if(root -> right)    R = check_AVL(root -> right);

    bool bal = (abs(L.ss - R.ss) <= 1 and L.ff and R.ff);   // Imp
    return {bal, max(L.ss, R.ss) + 1};
} 

// Idea: select v[mid] as root elem.
//       and call build() on [0, mid - 1] and [mid + 1, n] recursively...
node * build_AVL(const vector<ll> &v, int s, int e) {
    
    if(s > e)   return NULL;

    // if(s == e) {               // poses error in even sized vectore
    //     node * t = new node(v[e]);
    //     return t;
    // }

    int mid = (s + e) / 2;
    node * t = new node(v[mid]);
    t -> left = build_AVL(v, s, mid - 1);
    t -> right = build_AVL(v, mid + 1, e);

    return t;
}

node * build_pre_and_in(const vll & pre, const vll &in, int sp, int ep, int si, int ei) {

    if(sp > ep) return NULL;

    node * t = new node(pre[sp]);

    int root;
    f(i, si, ei) {
        if(in[i] == pre[sp]) {
            root = i;
            break;
        }
    }

    t -> left = build_pre_and_in(pre, in, sp+1, (sp+1) + (root-si) - 1, si, root - 1);
    t -> right = build_pre_and_in(pre, in, (sp+1) + (root-si), ep, root + 1, ei);
    return t;
}

//----------------------------------End of AVL-------------------------------------

// Use ideas of BFS
void print_right_view(node * root) {

    if(!root)   return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);  // marker

    while(!(sz(q) == 1 and q.front() == NULL)) {
        auto x = q.front(); q.pop();

        if(x == NULL) {
            q.push(NULL);
            continue;
        }

        if(x -> left)    q.push(x -> left);
        if(x -> right)    q.push(x -> right);

        if(sz(q) and q.front() == NULL) cout << x -> data << " ";
    } 
}

void print_right_view2(node * root) {

    if(!root)   return;

    queue<pair<node *, int>> q;   // {node, lvl}
    q.push({root, 0});

    while(!q.empty()) {
        auto x = q.front(); q.pop();
        
        if(x.ff -> left)    q.push({x.ff -> left, x.ss + 1});   
        if(x.ff -> right)    q.push({x.ff -> right, x.ss + 1});

        if((sz(q) and q.front().ss != x.ss) or (sz(q) == 0))  cout << x.ff -> data << " ";   // ⭐Imp
    }
}

void print_at_lvl(node * root, int k) {
    if(root == NULL)
        re;

    if(k == 0) {
        cout << root -> data << " ";
        re;
    }

    if(root -> left)    print_at_lvl(root -> left, k - 1);
    if(root -> right)    print_at_lvl(root -> right, k - 1);
}
int print_at_dist_K(node * root, node * target, int k) {
    if(!root)   return -1;

    if(root == target) {
        print_at_lvl(root, k);
        return 1;
    }

    if(root -> left) {
        int target_dist = print_at_dist_K(root -> left, target, k);
        if(target_dist == -1)
            return -1;
        else {
            if(target_dist == k)    cout << root -> data << " ";
            else if(k - target_dist - 1 >= 0)     print_at_lvl(root -> right, k - target_dist - 1);
        } 
        return target_dist + 1;
    }

    if(root -> right) {
        int target_dist = print_at_dist_K(root -> right, target, k);
        if(target_dist == -1)
            return -1;
        else {
            if(target_dist == k)    cout << root -> data << " ";
            else if(k - target_dist - 1 >= 0)    print_at_lvl(root -> left, k - target_dist - 1);
        } 
        return target_dist + 1;
    }
    
    return -1;
}

int main() {
    
    node * root = build();

    // int h = height(root);
    // cerr << "Height: " << h << endl;


    // printing all levels
    // f(i, 1, h)    level_order(root, i), ln;
    // level_order_BFS(root);
    // BFS(root);


    // cerr << "# Nodes " << count_nodes(root) << endl;
    // cerr << "# Sum_Nodes " << sum_nodes(root) << endl;


    // cerr << "Diameter: " << diameter(root) << endl;
    // cerr << "Diameter: " << diameterOpt(root).ss << endl;


    // sum_replace(root);
    // BFS(root);

    //---------------------------------------------------------------

    // cerr << (check_AVL(root).ff ? "AVL" : "Not AVL") << endl;


    // int n; cin >> n;
    // vll v(n); cin >> v;
    // node * root = build_AVL(v, 0, n - 1);
    // BFS(root);


    // int n; cin >> n;
    // vll pre(n), in(n); cin >> pre >> in;
    // node * root = build_pre_and_in(pre, in, 0, n - 1, 0, n - 1);
    // BFS(root);


    // print_right_view(root);     // M1
    // print_right_view2(root);     // M2


    // node * target = root -> left -> left;
    // int dist = 2;
    // print_at_dist_K(root, target, 1);


    return 0;
}


