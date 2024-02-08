#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t;
    while(t--) { 
        int n; cin >> n;
        int v[n];
        for(auto &x : v)    cin >> x; 

        // first 2 mx
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(auto x : v) {
            if(x > mx1) mx2 = mx1, mx1 = x;
            else if(x > mx2)    mx2 = x;    
        }
        cout << mx1 << " " << mx2 << endl;

        // first 3 mx
        // int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        // for(auto x : v)  {
        //     if(x > mx1) mx3 = mx2, mx2 = mx1, mx1 = x;
        //     else if(x > mx2)    mx3 = mx2, mx2 = x;
        //     else if(x > mx3)    mx3 = x;
        // }
        // cout << mx1 << " " << mx2 << " " << mx3 << endl;


        // first 2 mn
        // int mn1 = INT_MAX, mn2 = INT_MAX;
        // for(auto x : v) {
        //     if(x < mn1) mn2 = mn1, mn1 = x;
        //     else if(x < mn2)    mn2 = x;    
        // }
        // cout << mn1 << " " << mn2 << endl;
        
        // first 3 mn
        // int mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
        // for(auto x : v)  {
        //     if(x < mn1) mn3 = mn2, mn2 = mn1, mn1 = x;
        //     else if(x < mn2)    mn3 = mn2, mn2 = x;
        //     else if(x < mn3)    mn3 = x;
        // }
        // cout << mn1 << " " << mn2 << " " << mn3 << endl;

    }
    return 0;
}