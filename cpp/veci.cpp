#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void perms(int n, int s, vector<int>& d, vector<int>& sol) {
    if (s == d.size()-1) {
        int m = 0;
        for (auto digit : d) {
            m += digit;
            m *= 10;
        }
        m /= 10;
        if (m > n) {
            sol.push_back(m);
        }
        return;
    }

    for (int i = s; i < d.size(); ++i) {
        swap(d[i], d[s]);
        perms(n, s+1, d, sol);
        swap(d[i], d[s]);
    }
}

int main() {
    int n;
    cin >> n;

    int m = n;
    vector<int> digits, sols;
    while (m > 0) {
        digits.push_back(m % 10);
        m /= 10;
    }
    reverse(digits.begin(), digits.end());
    perms(n, 0, digits, sols);
    sort(sols.begin(), sols.end());

    if (sols.size() == 0) {
        cout << "0\n";
    } else {
        cout << sols[0] << endl;
    }
}