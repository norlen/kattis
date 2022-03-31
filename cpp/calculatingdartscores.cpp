#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<pair<int,int>, bool> memo;

bool solve(int n, int turn) {
    if (n < 0 || n != 0 && turn >= 3) {
        return false;
    }
    if (n == 0) {
        return true;
    }

    pair<int,int> key = {n, turn};
    if (memo.count(key)) {
        return memo[key];
    }

    for (int i = 3; i >= 1; --i) {
        for (int j = 1; j <= 20; ++j) {
            if (solve(n - i*j, turn+1)) {
                if (i == 1) {
                    cout << "single ";
                } else if (i == 2) {
                    cout << "double ";
                } else {
                    cout << "triple ";
                }
                cout << j << endl;
                return true;
            }
        }
    }

    memo[key] = false;
    return false;
}

int main() {
    int n;
    cin >> n;

    if (!solve(n, 0)) {
        cout << "impossible\n";
    }
}
