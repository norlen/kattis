#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<uint32_t, int>> A;
    vector<pair<uint32_t, int>> D;
    vector<pair<uint32_t, int>> H;
    set<int> s;

    for (int i = 0; i < n; ++i) {
        uint32_t a, d, h;
        cin >> a >> d >> h;

        A.push_back({a, i});
        D.push_back({d, i});
        H.push_back({h, i});
    }
    sort(A.rbegin(), A.rend());
    sort(D.rbegin(), D.rend());
    sort(H.rbegin(), H.rend());

    for (int i = 0; i < k; ++i) {
        s.insert(A[i].second);
        s.insert(D[i].second);
        s.insert(H[i].second);
    }

    cout << s.size() << endl;
}
