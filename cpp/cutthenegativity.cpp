#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct V {
    int a, b, c;
    
    V(int a, int b, int c): a(a), b(b), c(c) {}
};

int main() {
    int n;
    cin >> n;

    vector<V> values;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v;
            cin >> v;
            if (v != -1) {
                values.emplace_back(V(i+1, j+1, v));
            }
        }
    }

    sort(values.begin(), values.end(), [](const V& lhs, const V& rhs) {
        if (lhs.a != rhs.a) return lhs.a < rhs.a;
        if (lhs.b != rhs.b) return lhs.b < rhs.b;
        return lhs.c < rhs.c;
    });

    cout << values.size() << endl;
    for (const auto& v : values) {
        cout << v.a << " " << v.b << " " << v.c << endl;
    }
}
