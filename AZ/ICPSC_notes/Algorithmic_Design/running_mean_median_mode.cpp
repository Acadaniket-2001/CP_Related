#include <bits/stdc++.h>
using namespace std;
#define int long long

// problem: support:   insert an element
//                     remove an element
//                     mean, variance, median, mode of elements
//                     Do all above in sub-linear time.

struct data_dashboard { 
    // mean
    int sum = 0;
    double cnt = 0;

    // variance
    int sum_sq = 0;

    // median
    multiset<int> l, r;           

    // mode
    map<int, int> mp;            
    multiset<pair<int, int>> mst;      // mst<freq(x), x>

    void balance() {                // general concept
        if(l.size() == r.size())    return;
        else if(l.size() < r.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }   
        else if(l.size() > r.size() + 1) {
            r.insert(*l.rbegin());
            l.erase(--l.end());
        }
    }

    void insert(int x) {
        sum += x;
        sum_sq += x*x;
        cnt++;

        // median
        if(l.empty())   l.insert(x);
        else {
            if(x <= (*l.rbegin()) )    l.insert(x);
            else    r.insert(x);
        }
        balance();

        // mode
        auto it = mst.find({mp[x], x});
        if(it != mst.end())     mst.erase(it);
        mp[x]++; 
        mst.insert({mp[x], x});
    }

    void remove(int x) {
        sum -= x;
        sum_sq -= x*x;
        cnt--;

        // median
        if(x <= *l.rbegin())
            l.erase(l.find(x));      // assuming x to be deleted already exixts in dataset
        else
            r.erase(r.find(x));      // assuming x to be deleted already exixts in dataset
        balance();

        // mode 
        auto it = mst.find({mp[x], x});
        if(it != mst.end())    mst.erase(it);
        mp[x]--;
        mst.insert({mp[x], x});
    }

    double mean() {
        return sum / cnt; 
    }

    double variance() {
        return sum_sq / cnt - mean()*mean();
    }

    double median() {
        if((l.size() + r.size()) % 2) return (*l.rbegin());
        else return ( *l.rbegin() + (*r.begin()) ) / 2.0;
    }

    double mode() {
        return mst.rbegin() -> second;
    }
};

signed main() {

    data_dashboard ddb;
    ddb.insert(1);
    ddb.insert(2);
    ddb.insert(4);
    cout << ddb.mean() << endl;
    cout << ddb.variance() << endl;
    cout << ddb.median() << endl;
    cout << ddb.mode() << endl;
    ddb.remove(4);
    cout << " ------------------\n";
    cout << ddb.mean() << endl;
    cout << ddb.variance() << endl;
    cout << ddb.median() << endl;
    cout << ddb.mode() << endl;
    return 0;
}