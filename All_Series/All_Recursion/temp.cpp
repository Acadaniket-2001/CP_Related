#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) ((int)(x.size()))
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define MOD 1000000007
#define rep(i, a, b) for(ll i = a; i <= b; i++)
#define rrep(i, a, b) for(ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end() 

//top_Down_DP
ll dp[1004][1004];
ll minSmokeTD(const vector<int>& v, int i, int j) {
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    ll ans = INT_MAX;
    rep(k, i, j - 1) {
        
        ll l = 0, r = 0;

        rep(x, i, k) {
            l += v[x];
            l %= 100;
        }
        
        rep(x, k + 1, j) {
            r += v[x];
            r %= 100;
        }

        ans = min(ans, minSmokeTD(v, i, k) + minSmokeTD(v, k + 1, j) + l*r);
    }
    return dp[i][j] = ans;
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    while(scanf("%d", &n) != EOF) {
        // memset(dp, -1, sizeof dp);

        rep(i, 0, n - 1)
            rep(j, 0, n - 1)
                dp[i][j] = -1;

        vector<int> v(n);
        for(auto &x : v)    cin >> x;
        // cout << minSmoke(v, 0, n - 1) << endl;
        cout << minSmokeTD(v, 0, n - 1) << endl;
    }
    
    return 0;
}
