#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<int,int> get_win_lose(int p1, const string& m1, int p2, const string& m2) {
    if (m1 == m2) {
        return {-1, -1};
    }
    if (m1 == "rock") {
        if (m2 == "paper") {
            return {p2, p1};
        } else {
            return {p1, p2};
        }
    }
    if (m2 == "rock") {
        if (m1 == "paper") {
            return {p1, p2};
        } else {
            return {p2, p1};
        }
    }
    if (m1 == "paper") {
        if (m2 == "scissors") {
            return {p2, p1};
        } else {
            return {p1, p2};
        }
    }
    if (m2 == "paper") {
        if (m1 == "scissors") {
            return {p1, p2};
        } else {
            return {p2, p1};
        }
    }
    if (m1 == "scissors") {
        if (m2 == "rock") {
            return {p2, p1};
        } else {
            return {p1, p2};
        }
    }
    if (m2 == "scissors") {
        if (m1 == "rock") {
            return {p1, p2};
        } else {
            return {p2, p1};
        }
    }
    return {-1, -1};
}

int main() {
    bool first = true;
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0) break;
        if (!first) cout << endl;
        first = false;

        vector<pair<int,int>> m(n+1);

        int games = k*n*(n-1) / 2;
        for (int i = 0; i < games; ++i) {
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;

            // cout << "[" << m1 << "] [" << m2 << "]\n";
            auto wl = get_win_lose(p1, m1, p2, m2);
            if (wl.first == -1) continue;

            m[wl.first].first++;
            m[wl.second].second++;
        }

        for (int i = 1; i <= n; ++i) {
            int wins = m[i].first;
            int losses = m[i].second;
            int games = wins + losses;
            // cout << "p=" << kv.first << " wins=" << wins << ", losses=" << losses << ", games=" << games << endl;
            if (games == 0) {
                cout << "-\n";
            } else {
                double w = wins;
                double g = games;
                double ans = round(w*1000.0/g) / 1000.0;
                cout << fixed << setprecision(3) << ans << endl;
            }
        }
    }
}