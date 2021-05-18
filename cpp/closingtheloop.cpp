#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    constexpr int BLUE = 0, RED = 1;

    for (int i = 0; i < n; ++i) {
        vector<int> colors[2];
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int n;
            char c;
            cin >> n >> c;
            if (c == 'B') {
                colors[BLUE].push_back(n);
            } else {
                colors[RED].push_back(n);
            }
        }
        for (int i = 0; i < 2; ++i) sort(colors[i].rbegin(), colors[i].rend());

        int ans = 0;
        int shortest = colors[BLUE].size() > colors[RED].size() ? colors[RED].size() : colors[BLUE].size();
        if (shortest > 0) {
            int sidx = colors[BLUE][0] > colors[RED][0] ? BLUE : RED;

            ans += colors[sidx][0];
            for (int i = 0; i < shortest; ++i) {
                ans += colors[(sidx + 1) % 2][i];
            }
            for (int i = 0; i < shortest-1; ++i) {
                ans += colors[sidx][i+1];
            }
            ans -= shortest * 2;
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
}