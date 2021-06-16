#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];

    int s, low = INT32_MAX;
    for (int i = 0; i < n-2; ++i) {
        int h = max(d[i], d[i+2]);
        if (h < low) {
            s = i+1;
            low = h;
        }
    }
    cout << s << " " << low << endl;
}