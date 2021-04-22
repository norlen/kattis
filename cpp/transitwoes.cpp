#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s, t, n;
    cin >> s >> t >> n;

    auto d = vector<int>(n+1); // walk
    for (int i = 0; i < n+1; ++i) cin >> d[i];

    auto b = vector<int>(n); // bus time
    for (int i = 0; i < n; ++i) cin >> b[i];

    auto c = vector<int>(n); // bus interval; first leaves at zero
    for (int i = 0; i < n; ++i) cin >> c[i];

    int time = 0;
    for (int i = 0; i < n; ++i) {
        time += d[i];
        time += (c[i] - time % c[i]) % c[i]; // interval - left until interval, if time left == 0, then modulo to get to zero.
        time += b[i];
    }
    time += d[n];

    cout << (time <= t ? "yes" : "no") << endl;
}