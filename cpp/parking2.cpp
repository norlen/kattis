#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int stores, n;
        cin >> stores;
        int first = INT32_MAX;
        int last = 0;
        for (int j = 0; j < stores; ++j) {
            cin >> n;
            first = min(first, n);
            last = max(last, n);
        }
        cout << (last - first) * 2 << endl;
    }
}