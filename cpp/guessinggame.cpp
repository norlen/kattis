#include <iostream>

using namespace std;

int main() {
    while (true) {
        int low = 0;
        int high = 11;
        while (true) {
            int v;
            string s, t;
            cin >> v;
            if (v == 0) return 0;
            cin >> t >> s;

            if (s == "low") {
                low = max(low, v);
            } else if (s == "high") {
                high = min(high, v);
            } else {
                // Right on.
                if (v <= low || v >= high) {
                    cout << "Stan is dishonest" << endl;
                } else {
                    cout << "Stan may be honest" << endl;
                }
                break;
            }
        }
    }
}