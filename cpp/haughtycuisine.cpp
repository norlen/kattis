#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    string line;
    cin >> n;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> d(0, n-1);
    int r = d(gen);

    for (int i = 0; i < n; ++i) {
        if (i == r) {
            cin >> m;
            cout << m << endl;
            for (int j = 0; j < m; ++j) {
                cin >> line;
                cout << line << endl;
            }
            break;
        } else {
            getline(cin, line);
        }
    }
}
