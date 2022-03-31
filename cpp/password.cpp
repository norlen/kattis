#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    string s;
    double p, ans = 0;

    vector<double> probs;
    for (int i = 0; i < n; ++i) {
        cin >> s >> p;
        probs.push_back(p);
    }
    sort(probs.rbegin(), probs.rend());

    for (int i = 0; i < probs.size(); ++i) {
        ans += double(i+1) * probs[i];
    }

    cout << setprecision(8) << ans << endl;
}
