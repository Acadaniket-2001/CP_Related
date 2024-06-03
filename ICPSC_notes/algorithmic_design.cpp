#include <bits/stdc++.h>
using namespace std;

// problem: support:   insert an element
//                     remove an element
//                     count distinct element
//                     sum of all element
//                     max of all element

// Data structure to use : set -> no
//                         multiset -> no
//                         both th above -> yes but hefty
//                         map -> yes 

struct bag {
    int curr_sum = 0;            // curr_max can't be maintained like curr_sum as after deleting the current max: new max is not known
    map<int, int> mp;

    void insert(int a) {    // O(logN)
        curr_sum += a;
        mp[a]++;
    }

    void remove(int x) {    // O(logN)
        if(mp.find(x) != mp.end()) {
            curr_sum -= x;
            mp[x]--;
            if(mp[x] == 0)  mp.erase(x);
        }
    }

    int getdistinct() {     // O(1)
        return mp.size();
    }

    int getsum() {          // O(1)
        return curr_sum;
    }

    int getmax() {          //O(1)
        return mp.rbegin() -> first;
    }

    void debug() {
        for(auto e: mp) {
            cout << e.first << ":" << e.second << ", "; 
        }
        cout << endl;
    }
};

int main() {

    srand(time(0));
    bag bg;
    for(int i = 0; i < 10; i++) {
        bg.insert(rand() % 10);
    }
    bg.debug();
    return 0;
}

// ------------------------------------------------------------------------

