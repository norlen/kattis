#include <iostream>

using namespace std;

int main() {
    int n;
    int t = 1;
    while (cin >> n) {
        int min = INT32_MAX, max = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            min = std::min(min, c);
            max = std::max(max, c);
        }
        cout << "Case " << t << ": " << min << " " << max << " " << max-min << endl;
        t++;
    }
}