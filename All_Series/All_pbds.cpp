#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered set
template<class T> using pbset = tree<T, null_type, less<T>,
                        rb_tree_tag,tree_order_statistics_node_update> ;

// Ordered multiset
template<class T> using pbmultiset = tree<T, null_type, less_equal<T>, 
                        rb_tree_tag,tree_order_statistics_node_update> ;

/* ---------------------------------------------------------------------

    1.  PBDS WORKS ON -> Leetcode    Codeforces    Codechef    HackerRank
    
    2. find_by_order(k)  returns iterator to kth element starting from 0;
    
    3. order_of_key(k) returns count of elements strictly smaller than k;

------------------------------------------------------------------------*/

// void solve()
// {
//     pbset<long long> st;
//     // pbmultiset<long long> st;
//     st.insert(1);
//     st.insert(10);
//     st.insert(12);
//     st.insert(-11);
//     st.insert(1);
//     st.insert(20);

//     // returns the kth largest element till now O(log n)
//     for(int i = 0; i < st.size(); i++) {
//         cout << i << " " << *st.find_by_order(i) << endl; 
//     }
//     cout << "------------------------------" << endl;
    
//     // returns the index(expected index) of the element in the set in O(log n)
//     // returns the number of the element which are lesser than 'k' in the set 
//     // in short returns the lower_bound of the number in the set
//     // works as a substitute of segment tree in some cases

//     cout << st.order_of_key(12) << endl;
//     cout << st.order_of_key(8) << endl;
// }

// int main()
// {
//     // int _t; cin >> _t; while(_t--)
//     solve();
//     return 0;
// }

// -----------------------Inversion_count using pbds---------------------------------------------

// void solve()
// {
//     int n; cin >> n;
//     vector<int> v(n);
//     for(auto &x : v)    cin >> x;

//     pbmultiset<int> mst;
//     int cnt = 0;
//     for(int i = 0; i < n; i++) {
//         int smaller = mst.order_of_key(v[i]);
//         cnt += i - smaller;
//         mst.insert(v[i]);
//     }
//     cout << cnt << endl;
// }

// // Testcase
// // 1
// // 7
// // 1 5 2 3 6 4 10

// int main()
// {
//     // fastio();
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt", "w", stderr);
//     #endif

//     int _t; cin >> _t; while(_t--)
//     solve();
//     return 0;
// }

// ------------------Try problem 1324D -> codeforces-------------------