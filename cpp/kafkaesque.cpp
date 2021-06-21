#include <iostream>

using namespace std;

int main() {
    int k, m, prev = INT32_MAX, count = 0;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        cin >> m;
        if (prev > m) {
            count++;
        }
        prev = m;
    }

    cout << count << endl;
}