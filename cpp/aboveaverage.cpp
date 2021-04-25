#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;

    cout << fixed << setprecision(3);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        auto s = vector<int>(n);
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> s[j];
            sum += s[j];
        }
        sum /= n;

        int num_above = 0;
        for (const auto e : s) {
            if (e > sum) num_above++;
        }
        
        cout << static_cast<double>(num_above) / static_cast<double>(n) * 100 << "%\n";
    }
}