#include <iostream>

using namespace std;

int main() {
    int n, p, m;
    cin >> n >> p;

    int high = 0, curr = 0;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        curr += m - p;
        if (curr < 0) curr = 0;
        high = max(high, curr);
    }

    cout << high << endl;
}