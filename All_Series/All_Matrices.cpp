#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

// 1. Spiral traversal
//     hint : Use 4 pointers : l, r, t, b

// 2. Zig-Zag traversal
//     hint : gap strategy OR Coding blocks while(...) style

// 3. Rotation (In_place) ->
//      90, 180, 270(-90) -> clockwise
//      90, 180, 270(-90) -> anti - clockwise
//      hint : 1. transpose     ->     for all (i > j) : swap(a[i][j], a[j][i])
//             2. reverse all rows(for clockwise), all columns(for anti-clockwise)
//                Repeat step 1,2 once -> 90
//                Repeat step 1,2 twice -> 180
//                Repeat step 1,2 thrice -> 270   

/*-----------------------Transpose--------------------------

void solve()
{
    int n; cin >> n;
    int v[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > j)   swap(v[i][j], v[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t;
    while(t--)
        solve();
    return 0;
}

-----------------------------------------------------------*/

/*---------Rotate_by_90 (observation based)-------------------

void rotate_90_clockwise(vector<vector<int>>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; (n & 1) ? (j <= n / 2) : (j < n / 2); j++) {
            int temp = v[i][j];
            v[i][j] = v[n - 1 - j][i];
            v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
            v[n - 1 - i][n - 1 - j] = v[j][n - 1 - i];
            v[j][n - 1 - i] = temp;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t;
    while(t--) {

        int n; cin >> n;
        vector<vector<int>> v(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        rotate_90_clockwise(v);
            
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

-----------------------------------------------------------*/

