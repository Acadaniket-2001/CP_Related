#include <bits/stdc++.h>
using namespace std;


int MOD = 1e9 + 7;
const int N = 1e5 + 5;


/* Logic */
string t = "0100";
int dp[N][8];
int n;


int C(int N, int r){
	if (r > N) return 0;
	if(r == 0) return 1;
	if(r == 1) return N;
	if(r == 2) return N*(N-1)/2;
	return N*(N-1)*(N-2)/6;
}


int f(int i, int match){
	if(match == 4) return 0;
	if(i == n) return 1;
	if(dp[i][match] != -1) return dp[i][match];


	int ans = f(i + 1, match) + f(i + 1, match + 1);
	return dp[i][match] = ans;
}


int g1(int i, int mask){
	if(i == n) return 1;
	if(dp[i][mask] != -1) return dp[i][mask];


	int ans = 0;
	if(i >= 3 and mask == 2) ans = g1(i + 1, 5);
	else ans = g1(i + 1, (mask << 1 | 0)&7) + g1(i + 1, (mask << 1 | 1)&7);
	return dp[i][mask] = ans;
}


int g2(int i, int state){
	if(i == n) return 1;
	if(dp[i][state] != -1) return dp[i][state];
	int ans = 0;
	if(state == 0) ans += g2(i + 1, state) + g2(i + 1, 1);
	else if(state == 1) ans += g2(i + 1, state) + g2(i + 1, 2);
	else if(state == 2) ans += g2(i + 1, 0) + g2(i + 1, 3);
	else ans += g2(i + 1, 2);
	return dp[i][state] = ans;
}


int findSubseq(){
	memset(dp, -1, sizeof(dp));
	return f(0,0);
}


int findSubseqUsingMaths(){
	if(n < 3) return 1<<n;
	return C(n,0) + C(n,1) + C(n,2) + C(n,3);
}


int findSubstrUsingBitMask(){
	memset(dp, -1, sizeof(dp));
	return g1(0,0);
}


int findSubstrUsingAutomata(){
	memset(dp, -1, sizeof(dp));
	return g2(0,0);
}


void solve(){
	cin >> n;
	// cout << findSubseq() << "\n";
	// cout << findSubseqUsingMaths() << "\n";
	cout << findSubstrUsingBitMask() << "\n";
	cout << findSubstrUsingAutomata() << "\n";
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    // cin >> tests;
    while(tests--){
        solve();
    }
}
