#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((int)x.size())
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rrep(i, a, b) for(int i = b; i >= a; i--)

/*----------------------------check if arr[] is sorted----------------------------------------

bool is_Sorted(const vector<int>& v, int i, int j)
{
    if(i == j  ||  j == -1) {
        return 1;
    }
    return (is_Sorted(v, i, j - 1)  &&  v[j - 1] <= v[j]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v) cin >> x;
        cout << (is_Sorted(v, 0 ,n-1) ? "YES" : "NO") << endl;
    }

    return 0;
}
----------------------------------------------------------------------*/

/*----------------------------recursive binary search------------------------------------------

int binS(const vector<int>& v, int i, int j, int x) {
    if(i <= j) {
        int mid = (i + j) / 2;
        if(v[mid] == x)     return mid;
        if(v[mid] < x)     return binS(v, mid + 1, j, x);
        else    return binS(v, i, mid - 1, x);
    }
    return -1;
}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout  << x <<  " -> " << binS(v, 0, n - 1, x) << endl;
    }


    return 0;
}
----------------------------------------------------------------------*/

/*----------------------------recursive fast exponentiation------------------------------------------

unsigned long long pow(int a ,int b) {
    if(b == 0) return 1;
    if(b % 2)   return a * pow(a, b - 1);
    else {
        unsigned int x = pow(a, b / 2);
        return x * x;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << a << "^" << b << " -> " <<  pow(a, b) <<  endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------recursive (a * b)------------------------------------------

int mul(int a, int b) {
    if(b == 0)
        return 0;
    return a + mul(a, b - 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << a << "*" << b << " -> " <<  mul(a, b) <<  endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------recursive linear search(1st , last, all occurances)---------------------

int linfirst(const vector<int>& v, int i, int j, int x) {
    if(i == j + 1) {
        return -1;
    }
    if(v[i] == x)
        return i;
    else 
        return linfirst(v, i + 1, j, x);
}

int linLast(const vector<int>& v, int i, int j, int x) {
    if(j == i - 1) {
        return -1;
    }
    if(v[j] == x)
        return j;
    else
        return linLast(v, i, j - 1, x);
}

void allOccur(const vector<int>& v, int i, int j, int x) {
    if(i == j + 1) {
        return;
    }
    if(v[i] == x)   cout << i << " ";
    allOccur(v, i + 1, j, x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v)    cin >> x;
    int q; cin >> q;
    while(q--) {
        int x ; cin >> x;
        cout << x << " -> " << linfirst(v, 0, n - 1, x) << "  ";
        allOccur(v, 0, n - 1, x);
        cout << "  "; 
        cout << linLast(v, 0, n - 1, x) << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------recursive bubble sort------------------------------------------

                                                    //to be discussed

void place(vector<int>& v, int i, int j) {
    if(i == j)  return;
    if(v[i] > v[i + 1])
        swap(v[i], v[i + 1]);
    place(v, i + 1, j);
} 

void bubble_sort(vector<int>& v, int i, int j) {
    if(i == j) {
        return;
    }

    // for(int x = 0; x <= j - 1; x++) {        // recursive version of this for() loop is place()
    //     if(v[x] > v[x + 1]) {
    //         swap(v[x], v[x + 1]);
    //     }
    // }
    place(v, 0, j);

    bubble_sort(v, i, j - 1);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        bubble_sort(v, 0, n - 1);
        for(auto &x : v)    cout << x << ' ';
        cout << endl;
    }


    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------check if string is palindrome------------------------------------------

bool isPalindrome(string s, int i, int j) {

    if(i > j)
        return 1;
    if(s[i] == s[j])
        return isPalindrome(s, i + 1, j - 1);
    else
        return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        cout << s << " -> " << (isPalindrome(s, 0, s.size() - 1) ? "YES" : "NO") << endl; 
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------merge sort---------------------------------------------


void merge(vector<int>& v, int s, int mid, int e) {

    vector<int> ans;
    int i = s, j = mid + 1;
    while(i <= mid  ||  j <= e) {
        if(i == mid + 1)
            ans.push_back(v[j++]);
        else if(j == e + 1)
            ans.push_back(v[i++]);
        else {
            if(v[i] < v[j])     ans.push_back(v[i++]);
            else     ans.push_back(v[j++]);
        }
    }
    for(int i = s, x = 0; i <= e; i++) {
        v[i] = ans[x++];
    }
}

void merge_sort(vector<int>& v, int i, int j) {
    if(i >= j)
        return;
    int mid = (i + j) / 2;
    
    merge_sort(v, i, mid);
    merge_sort(v, mid + 1, j);

    merge(v, i, mid, j);

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        merge_sort(v, 0, n - 1);
        for(auto x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------Quick_Sort-----------------------------------------
                              
                                // watch CB video on having doubt

int partition(vector<int>& v, int s,int e) {
    int i = s - 1;
    int j = s;
    for(; j <= e - 1; j++) {
        if(v[j] <= v[e]) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[e]);
    return i + 1;
}

void quick_sort(vector<int> &v, int s, int e) {
    if(s >= e)
        return;
    int pivot = partition(v, s, e);
    quick_sort(v, s, pivot - 1);
    quick_sort(v, pivot + 1, e);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        quick_sort(v, 0, n - 1);
        for(auto x: v)  cout << x << ' ';
        cout << endl;
    }

    return 0;
}

---------------------------------------------------------------------*/

/*----------------------------inversion count---------------------------------------------

int cnt_cross_inv(vector<int> v, int s, int mid, int e) {

    int i = s, j = mid + 1, ans = 0;
    vector<int> merge;
    while(i <= mid  ||  j <= e) {
        if(i == mid + 1)
            merge.push_back(v[j++]);
        else if(j == e + 1)
            merge.push_back(v[i++]);
        else {
            if(v[i] > v[j]) {
                ans += mid - i  + 1;
                merge.push_back(v[j++]);
            }
            else
                merge.push_back(v[i++]);
        }
    }
    for(int i = s, x = 0; i <= e; i++)
        v[i] = merge[x++];

    return ans;
}

int inv_count(vector<int> v, int s, int e) {

    if(s == e)
        return 0;

    int mid = (s + e) / 2;
    int x = inv_count(v, s, mid);
    int y = inv_count(v, mid + 1, e);
    int z = cnt_cross_inv(v, s ,mid, e);

    return x + y + z;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        cout << inv_count(v, 0, n - 1) << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------number to spelling------------------------------------------

vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void ntos(int n) {
    if(n == 0)  return;

    ntos(n / 10);
    cout << v[n % 10] << " ";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ntos(n);
        cout << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------stoi()---------------------------------------------

int stoi(string s, int i, int j) {
    if(i == j)  return s[i] - '0';
    return stoi(s,i, j - 1) * 10 + (s[j] - '0');
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << stoi(s, 0, (int)s.size() - 1) << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------replace_pi---------------------------------------------

void replace_pi(char* s, int i) {
    if(s[i] == '\0'){
        return;
    }

    if(s[i] == 'p'  &&  s[i + 1] == 'i') {
        
        int j = i + 2;
        while(s[j] != '\0') j++;
        j++;

        while(j - 2 >= i + 2) {
            s[j] = s[j - 2];
            j--;
        }
        s[i] = '3';
        s[i + 1] = '.';
        s[i + 2] = '1';
        s[i + 3] = '4';

        replace_pi(s, i + 4);
    }
    else
        replace_pi(s, i + 1);

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        char s[100005]; cin >> s;
        replace_pi(s, 0);
        cout << s << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------tilling_problem-----------------------------------------

int tilling_ways(int n) {
    if(n < 4)
        return 1;
    return tilling_ways(n - 1) + tilling_ways(n - 4);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << tilling_ways(n) << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------ladder_problem---------------------------------------------
                            
                            
                                //do once again (see CB lectures for doubts)
int ways(int n, int k){
    if(n == 0)
        return 1;
    if(n < 0) 
        return 0;

    int ans = 0;
    for(int i=1; i<=k; i++)
        ans += ways(n - i, k);
    return ans;
}


signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        cout << ways(n, k) << endl;
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------friends_and_bikes------------------------------------------
                            //learnt how to analyse

int ways(int n) {
    if(n == 0 ||  n == 1)
        return 1;
    return 1 * ways(n - 1) + (n - 1) * ways(n - 2);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << ways(n) << endl;

    }

    return 0;
}


----------------------------------------------------------------------*/

/*----------------------------optimal_binary_strings------------------------------------------

int count(int n) {
    if(n == 0)  return 1;
    if(n == 1)  return 2;
    return count(n - 1) + count(n - 2);
}


signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << count(n) << endl;
    }

    return 0;
}


----------------------------------------------------------------------*/

/*----------------------------tower_of_hanoi---------------------------------------------

void move(int n, char src, char helper, char dst) {
    if(n == 1) {
        cout << "Move " << n << " : " << src << " -> " << dst << endl;
        return;
    }
    move(n - 1, src, dst, helper);
    cout << "Move " << n << " : " << src <<" -> " << dst << endl;
    move(n - 1, helper, src, dst);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        move(n,'A', 'B', 'C');        
    }

    return 0;
}

----------------------------------------------------------------------*/

// Subset based problems  ------>  Backtracking

/*----------------------------generate_subsequences---------------------------------------------

// method 1 (storing all subsets)

void subsequence(string s, int i, int j, vector<string>& v) {
    if(i == j) {
        v.push_back("");
        v.push_back(string(1, s[i]));
        return;
    }
    subsequence(s, i + 1, j, v);
    int n = v.size();
    for(int x=0; x<n; x++)
        v.push_back(s[i] + v[x]);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        vector<string> v;
        subsequence(s, 0, s.size() - 1, v);
        for(auto x : v)
            cout << x << " ";
        
        cout << endl;
    }

    return 0;
}


// method 2 (printing all subsets)

void subsequence(string& s, int i, string& sub) {
    if(i == (int)s.size()) {
        cout << sub << endl;
        return;
    }
    sub += s[i];
    subsequence(s, i + 1, sub);
    sub.pop_back();
    subsequence(s, i + 1, sub);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        string sub;
        subsequence(s, 0, sub);
    }

    return 0;
}



----------------------------------------------------------------------*/

/*----------------------------generate_valid_brackets ------------------------------------------
                                // revise it
void valid_brackets(int n, int open, int close, string& s) {
    if(open == n  &&  close == n) {
        cout << s << endl;
        return;
    }

    if(open < n) {
        s += '(';
        valid_brackets(n, open + 1, close, s);
        s.pop_back();
    }
    
    if(close < open) {
        s += ')';
        valid_brackets(n, open, close + 1, s);
        s.pop_back();
    }
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s;
        valid_brackets(n, 0, 0, s);
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------01_Knapsack_problem---------------------------------------------

int mx_price(const vector<pair<int, int>>& com, int sum, int i, int c, vector<pair<int, int>>& sub, int ans) {
    if(i == com.size()) {
        int t = 0;
        for(auto &x : sub)
            t += x.ss;
        return max(ans, t);
    }
    if(sum + com[i].ff <= c) {
        sub.pb(com[i]);
        ans = max(mx_price(com, sum + com[i].ff, i + 1, c, sub, ans), ans);
        sub.ppb();
    }
    ans = max(mx_price(com, sum, i + 1, c, sub, ans), ans);
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;
        int ans = -1;
        vector<pair<int, int>> com(n), sub;
        int p, w;
        for(auto &x : com) {
            cin >> w >> p;
            x = {w, p};
        }
        cout << mx_price(com, 0, 0, c, sub, ans);
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------generate_keypad_combinations------------------------------------------

void generate_strings(vector<int>& v, int i, string& s, vector<vector<char>>& pad) {
    if(i == v.size()) {
        cout << s << endl;
        return;
    }

    for(int x = 0; x < pad[v[i]].size(); x++) {
        s += pad[v[i]][x];
        generate_strings(v, i + 1, s, pad);
        s.ppb();
    }

}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        vector<vector<char>> pad = {{'+'}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        string s;
        generate_strings(v, 0, s, pad);
    }

    return 0;
}

----------------------------------------------------------------------*/

/*----------------------------alphabetic_string_generation-----------------------------------------

void generate_string(vector<int>& v, string& s, int i) {
    // base case
    if(i == sz(v)) {
        cout << s << endl;
        return;
    }

    // rec case
    // pick single
    s += v[i] + 'A' - 1;
    generate_string(v, s, i + 1);
    s.ppb();

    // pick double
    if(i + 1 < sz(v)) {
        int nxt = v[i] * 10 + v[i + 1];
        if(nxt <= 26) {
            s += nxt + 'A' - 1;
            generate_string(v, s, i + 2);
            s.ppb();
        }
    }
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v)    cin >> x;

    string s;
    generate_string(v, s, 0);
    return 0;
}

// ---------------------------------------------------------------------*/

/*----------------------------rat_in_a_maze-----------------------------------------

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

// int di[] = {0, 0, -1, 1};
// int dj[] = {1, -1, 0, 0};
// string dir = "RLUD";

// void print_all_paths(vector<vector<char>>& maze, int i, int j, vector<vector<char>>& soln, int n, int m, string& s) {
//     if(i == n - 1  &&  j == m - 1) {
//         cout << s << endl;
//         soln[i][j] = '1';
//         rep(i, 0, n - 1) {
//             rep(j, 0, m - 1) {
//                 cout << soln[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << "----------\n";
//         return;
//     }

//     if(i < 0  ||  j < 0  ||  i >= n  ||  j >= m  ||  maze[i][j] == 'X')
//         return;
    
//     maze[i][j] = 'X';
//     soln[i][j] = '1';
//     for(int x = 0; x < 4; x++) {
//         s += dir[x];
//         print_all_paths(maze, i + di[x], j + dj[x], soln, n, m, s);
//         s.ppb();
//     }
//     soln[i][j] = '0';
//     maze[i][j] = '0';
// }

// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n, m; cin >> n >> m;
//         vector<vector<char>> maze(n, vector<char>(m, '0'));
//         vector<vector<char>> soln(n, vector<char>(m, '0'));
//         rep(i, 0, n - 1)
//             rep(j,0, m - 1)
//                 cin >> maze[i][j];
//         string s;
//         print_all_paths(maze, 0, 0, soln, n, m, s);
//     }

//     return 0;
// }

------------------------------------------------------------------------------------*/

/*----------------------------print_permutations(all / unique)----------------------------------------

void permutations(string &s, int i, set<string>& st) {
    if(i == sz(s)) {
        if(!st.count(s)) {
            cout << s << endl;
            st.insert(s);
        }
        return;
    }
    
    for(int x = i; x < sz(s); x++) {

        // things written before recursive function call are for moving (top -> down) in recursion tree
        swap(s[i], s[x]);
        
        permutations(s, i + 1, st);
        
        // things written after recursive function call are for moving (down -> top) in recursion tree
        swap(s[i], s[x]);
    }
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    set<string> st;
    permutations(s, 0, st);
    return 0;
}
---------------------------------------------------------------------*/

/*----------------------------Sudoku_Solver----------------------------------------
                                // to do once again
bool canPlace(vector<vector<int>>& board, int i, int j, int n, int num) {

    for(int x = 0; x < n; x++) {
        if(board[i][x] == num  ||  board[x][j] == num)
            return false;
    }

    int rn = sqrt(n);
    int i_sb = i / rn * rn;
    int j_sb = j / rn * rn;
    for(int x = 0; x < rn; x++) {
        for(int y = 0; y < rn; y++) {
            if(board[i_sb + x][j_sb + y] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>>& board, int i, int j, int n) {
    if(i == n) {
        cout <<  "-----------------\n";
        rep(i, 0, n - 1){
            rep(j, 0, n - 1) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if(j == n)
        return solve(board, i + 1, 0, n);

    if(board[i][j] != 0)
        return solve(board, i, j + 1, n);

    for(int num = 1; num <= n; num++) {
        if(canPlace(board, i, j, n, num)) {
            board[i][j] = num;
            bool is_solved = solve(board, i, j + 1, n);
            if(is_solved) {
                return true;
            }
        }
    }
    //Backtracking step
    board[i][j] = 0;                 //important step
    return false;
    
}

signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));

    rep(i, 0, n - 1)
        rep(j, 0, n - 1)
            cin >> board[i][j];

    bool ans = solve(board, 0, 0, n);
    if(!ans)
        cout << "Wrong Sudoku !" << endl;

    return 0;
}

---------------------------------------------------------------------*/

/*----------------------------N-Queens_Visualiser-----------------------------------------
               
                                // must watch CB video on N-Queens -> becoz has summary 
// to count/print one soln.

// bool canPlace(const vector<vector<char>>& soln, int n, int i, int j) {
    
//     for(int x = 0; x < i; x++) {
//         if(soln[x][j] == 'Q')
//             return 0;
//     }

//     int x = i, y = j;
//     while(x >= 0  &&  y >= 0) {
//         if(soln[x][y] == 'Q')
//             return 0;
//         x--, y--;
//     }

//     x = i, y = j;
//     while(x >= 0  &&  y < n) {
//         if(soln[x][y] == 'Q')
//             return 0;
//         x--, y++;
//     }

//     return 1;
// }

// bool place_queens(int n, vector<vector<char>>& soln, int i, int j) {
//     if(i == n) {
//         rep(x, 0, n - 1) {
//             rep(y, 0, n - 1) {
//                 cout << soln[x][y] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//         return 0;          //hack -> return 1 to print one combination and return 0 to print all combinations
//     }

//     for(int x = 0; x < n; x++) {
//         if(canPlace(soln, n, i, x)) {
//             soln[i][x] = 'Q';
//             bool is_solved = place_queens(n, soln, i + 1, 0);
//             if(is_solved)
//                 return 1;
//             soln[i][x] = '.';
//         }
//     }
//     return 0;
// }

// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n; cin >> n;
//         vector<vector<char>> soln(n ,vector<char>(n, '.'));
//         place_queens(n, soln, 0, 0); 
//     }

//     return 0;
// }


// to count / print all soln.

// bool canPlace(const vector<vector<char>>& soln, int n, int i, int j) {
    
//     for(int x = 0; x < i; x++) {
//         if(soln[x][j] == 'Q')
//             return 0;
//     }

//     int x = i, y = j;
//     while(x >= 0  &&  y >= 0) {
//         if(soln[x][y] == 'Q')
//             return 0;
//         x--, y--;
//     }

//     x = i, y = j;
//     while(x >= 0  &&  y < n) {
//         if(soln[x][y] == 'Q')
//             return 0;
//         x--, y++;
//     }

//     return 1;
// }

// int place_queens(int n, vector<vector<char>>& soln, int i, int j) {
//     if(i == n) 
//         return 1;     
        
//     int cnt = 0;
//     for(int x = 0; x < n; x++) {
//         if(canPlace(soln, n, i, x)) {
//             soln[i][x] = 'Q';
//             cnt += place_queens(n, soln, i + 1, 0);
//             soln[i][x] = '.';
//         }
//     }
//     return cnt;
// }

// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n; cin >> n;
//         vector<vector<char>> soln(n ,vector<char>(n, '.'));
//         cout << place_queens(n, soln, 0, 0) << endl; 
//     }

//     return 0;
// }


// Optimised(canPlace) in N_Queens

// bitset<1000> col(0), ld(0), rd(0);         //boolean array can also be used , bitset is space optimal

// int place_queens(int n, int i) {
//     if(i == n) {
//         return 1;
//     }

//     int cnt = 0;
//     for(int j = 0; j < n; j++) {
//         if(!col[j]  &&  !ld[j - i + n - 1]  &&  !rd[i + j]) {
//             col[j] = ld[j - i  + n - 1] = rd[i + j] = 1;
//             cnt += place_queens(n, i + 1);
//             col[j] = ld[j - i + n - 1] = rd[i + j] =  0;
//         }
//     }
//     return cnt;
// }

// signed main()
// { 
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while(t--) {
//         int n; cin >> n;
//         vector<vector<char>> board(n ,vector<char>(n, '.'));
//         cout << place_queens(n, 0) << endl; 
//     }

//     return 0;
// }

---------------------------------------------------------------------*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << n + 1 << endl;
    }
    return 0;
}