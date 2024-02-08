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


/*-----------------------------------------rat_in_a_maze-----------------------------------------*/

                                // printing all path

// void print_paths(vector<vector<char>>& maze, int i, int j, vector<vector<int>>& soln, int m, int n) {
//     if(i == n - 1  &&  j == m - 1) {
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 cout << soln[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << "------------------\n";
//         return;
//     }

//     // right
//     if (j + 1 < m  &&  maze[i][j + 1] != 'X') {
//         soln[i][j + 1] = 1;
//         print_paths(maze, i, j + 1, soln, m ,n);
//         soln[i][j + 1] = 0;  
//     }

//     // down
//     if(i + 1 < n  &&  maze[i + 1][j] != 'X') {
//         soln[i + 1][j] = 1;
//         print_paths(maze, i + 1, j, soln, m ,n);
//         soln[i + 1][j] = 0;
//     }
// }

// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n, m; cin >> n >> m;
//         vector<vector<char>> maze(n, vector<char>(m));
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 cin >> maze[i][j];
//             }
//         }
    
//         vector<vector<int>> soln(n, vector<int>(m, 0));
//         soln[0][0] = 1;
//         print_paths(maze, 0, 0, soln, m, n);
//     }
//     return 0;
// }

                                // printing single path

// bool find_path(vector<vector<int>>& maze, int i, int j, int n, int m) {

//     if(i == n - 1  &&  j == m - 1) {
//         maze[i][j] = 2;
//         cout << "-------------------\n";
//         rep(i, 0, n - 1) {
//             rep(j, 0, m - 1) {
//                 cout << maze[i][j] << " ";
//             }
//             cout << endl;
//         }
//         return 1;
//     }

//     if(i == n  ||  j == m  ||  maze[i][j] == 1)
//         return 0;

//     maze[i][j] = 2;       // '2' is the path and '1' is trap
    
//     bool right = find_path(maze, i, j + 1, n, m);
//     if(right)   return 1;

//     bool down = find_path(maze, i + 1, j, n, m);
//     if(down)    return 1;
//     maze[i][j] = 0;

//     return 0;
// }

// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n, m; cin >> n >> m;
//         vector<vector<int>> maze(n, vector<int>(m, 0));
//         rep(i, 0, n - 1)
//             rep(j,0, m - 1)
//                 cin >> maze[i][j];

//         bool ans = find_path(maze, 0, 0, n, m);
//         if(!ans)
//             cout << "No path exists.\n";
//     }

//     return 0;
// }

                                // counting all paths

// int count_paths_m1(vector<vector<char>>& maze, int i, int j, int n ,int m) {
//     if(i >= n  ||  j >= m  ||  maze[i][j] == 'X')
//         return 0;
//     if(i == n - 1  &&  j == m - 1) {
//         return 1;
//     }

//     //count right paths
//     int right = count_paths_m1(maze, i , j + 1, n, m);
//     //count down paths
//     int down = count_paths_m1(maze, i + 1 , j, n, m);

//     return right + down;
// }

// int count_paths_m2(vector<vector<char>>& maze, int i, int j, int n ,int m) {
//     if(i == n - 1  &&  j == m - 1) {
//         return 1;
//     }
    
//     int r = 0, d = 0;
//     if(j + 1 < m  &&  maze[i][j + 1] != 'X') {
//         r = count_paths_m2(maze, i ,j + 1, n, m);
//     }
//     if(i + 1 < n  &&  maze[i + 1][j] != 'X') {
//         d = count_paths_m2(maze, i + 1, j, n, m);
//     }
//     return r + d;
// }


// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n, m; cin >> n >> m;
//         vector<vector<char>> maze(n, vector<char>(m));
//         for(int i=0; i<n; i++) {
//             for(int j= 0; j< m; j++) {
//                 cin >> maze[i][j];
//             }
//         }
//         cout << count_paths_m1(maze, 0, 0, n, m) << endl;
//         cout << count_paths_m2(maze, 0, 0, n, m) << endl;
//     }
//     return 0;
// }


                                // Modified rat in a maze --up, down, left, right

int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};
string dir = "RLUD";

void print_all_paths(vector<vector<char>>& maze, int i, int j, vector<vector<char>>& soln, int n, int m, string& s) {
    if(i == n - 1  &&  j == m - 1) {
        cout << s << endl;
        soln[i][j] = '1';
        f(i, 0, n - 1) {
            f(j, 0, m - 1) {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----------\n";
        return;
    }

    if(i < 0  ||  j < 0  ||  i >= n  ||  j >= m  ||  maze[i][j] == 'X')
        return;
    
    maze[i][j] = 'X';
    soln[i][j] = '1';
    for(int x = 0; x < 4; x++) {
        s += dir[x];
        print_all_paths(maze, i + di[x], j + dj[x], soln, n, m, s);
        s.ppb();
    }
    soln[i][j] = '0';
    maze[i][j] = '0';
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> maze(n, vector<char>(m, '0'));
        vector<vector<char>> soln(n, vector<char>(m, '0'));
        f(i, 0, n - 1)
            f(j,0, m - 1)
                cin >> maze[i][j];
        string s;
        print_all_paths(maze, 0, 0, soln, n, m, s);
    }

    return 0;
}