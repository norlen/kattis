#include <iostream>
#include <array>
#include <vector>

using namespace std;

bool solve(const array<int, 9>& d, int s, int left, int sum, vector<int>& out) {
    if (sum > 100) {
        return false;
    }
    if (out.size() == 7) {
        return sum == 100;
    }

    for (int i = s; i < d.size(); ++i) {
        out.push_back(d[i]);
        sum += d[i];
        if (solve(d, i+1, left-1, sum, out)) {
            return true;
        }
        sum -= d[i];
        out.pop_back();
    }
    return false;
}

int main() {
    array<int, 9> d;
    for (int i = 0; i < d.size(); ++i) cin >> d[i];

    vector<int> out;

    solve(d, 0, 9, 0, out);
    for (int i = 0; i < out.size(); ++i) cout << out[i] << endl;
}