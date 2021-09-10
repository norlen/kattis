#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<float>& vals, const float WIDTH, float w) {
    sort(vals.begin(), vals.end());

    // cout << endl << "CHECK width=" << WIDTH << ", w=" << w << endl;

    float s = 0.0;
    for (int i = 0; i < vals.size(); ++i) {
        float min = vals[i] - w;
        float max = vals[i] + w;
        // cout << "i=" << i << ", s=" << s << ", min=" << min << ", max=" << max << endl;
        if (s < min) {
            return false;
        }
        s = max;
        if (s >= WIDTH) {
            break;
        }
    }
    return s >= WIDTH;
}

int main() {
    while (true) {
        int n, m;
        float w;
        cin >> n >> m >> w;
        if (n == 0 && m == 0) break;

        vector<float> xs(n);
        vector<float> ys(m);
        for (int i = 0; i < n; ++i) cin >> xs[i];
        for (int i = 0; i < m; ++i) cin >> ys[i];

        float LENGTH = 100;
        float WIDTH = 75;

        if (check(xs, WIDTH, w / 2.0) && check(ys, LENGTH, w / 2.0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}