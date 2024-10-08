
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t

int n;

int dp[105][100100];
bool rec(vector<int> &v, int i, int sum_left) {         // 🧠 taking rec(i, sum_taken) -> will not help in caching across queries
    // pruning
    if(sum_left < 0)
        return 0;

    // base case
    if(i == n)
        return (sum_left == 0);
    
    // cache
    if(dp[i][sum_left] != -1)
        return dp[i][sum_left];

    // Xition
    bool ans = rec(v, i + 1, sum_left);
    if(sum_left >= v[i])
        ans |= rec(v, i + 1, sum_left - v[i]);

    //save and ret
    return dp[i][sum_left] = ans;
}

vector<int> solution;
void generate(vector<int> &v, int i, int sum_left) {
    // base case
    if(i == n)
        return;
    
    // find the correct Xition
    if(rec(v, i + 1, sum_left)) {
        generate(v, i + 1, sum_left);
    }
    else if(rec(v, i + 1, sum_left - v[i])) {
        solution.push_back(i);
        generate(v, i + 1, sum_left - v[i]);
    }
}

vector<vector<int>> subset_queries(vector<int> &v, vector<int> &q) {
    n = v.size();
    vector<vector<int>> ans;

    memset(dp, -1, sizeof dp);                  // ⭐ O(#S = N.S) + O(DP = N.S)

    for(auto e: q) {
        if(rec(v, 0, e)) {                      // ⭐ O(1) : Ammortised
            generate(v, 0, e);
            ans.push_back(solution);
            solution.clear();
        }
        else {
            ans.push_back({-1});
        }
    }
    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
