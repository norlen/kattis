#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    bool first = true;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        if (first) first = false;
        else cout << endl;

        vector<pair<int, int>> as;
        vector<int> bs;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            as.push_back({a, as.size()});
        }
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            bs.push_back(b);
        }

        sort(as.begin(), as.end());
        sort(bs.begin(), bs.end());

        vector<int> f(as.size());
        for (int i = 0; i < n; ++i) {
            f[as[i].second] = bs[i];
        }

        for (const auto e : f) {
            cout << e << endl;
        }
    }
}