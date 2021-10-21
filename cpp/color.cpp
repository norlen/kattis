#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s, c, k;
    cin >> s >> c >> k;

    vector<int> socks(s);
    for (int i = 0; i < s; ++i) cin >> socks[i];
    sort(socks.begin(), socks.end());

    int machines = 0;
    int curr = 0;
    int kstart = socks[0];
    for (int i = 0; i < s; ++i) {
        if (curr >= c || abs(socks[i] - kstart) > k) {
            machines++;
            kstart = socks[i];
            curr = 0;
        }
        curr++;
    }
    if (curr > 0) {
        machines++;
    }

    cout << machines << endl;
}