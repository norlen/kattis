#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> ds;

bool same_or_zero(int i) {
    while (i > 0) {
        int d = i % 10;
        if (d == 0) return true;
        
        if (ds.count(d) > 0) return true;
        ds.insert(d);
        i /= 10;
    }
    return ds.size() != 6;
}

int divis(int i) {
    int n = 0;
    for (int j = 1; j < 10; ++j) {
        if (i % j == 0 && ds.count(j) > 0) {
            n++;
        }
    }
    return n;
}

int main() {
    int l, h;
    cin >> l >> h;
    int solutions = 0;

    for (int i = l; i <= h; ++i) {
        ds.clear();
        if (!same_or_zero(i) && divis(i) >= 6) {
            solutions++;
        }
    }
    cout << solutions << endl;
}