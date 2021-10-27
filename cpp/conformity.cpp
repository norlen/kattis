#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> courses(5);
    unordered_map<ll, ll> m;
    ll maxcount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> courses[j];
        }
        sort(courses.begin(), courses.end());

        ll comb = 0;
        for (ll c : courses) {
            comb *= 1000;
            comb += c;
        }

        if (m.count(comb) == 0) m.insert({comb, 0});
        m[comb] += 1;
        maxcount = max(maxcount, m[comb]);
    }

    ll num_students = 0;
    for (auto kv : m) {
        if (kv.second == maxcount) {
            num_students += kv.second;
        }
    }

    cout << num_students << endl;
}
