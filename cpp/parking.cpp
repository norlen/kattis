#include <iostream>

using namespace std;

int main() {
    int cost[4];
    cost[0] = 0;
    for (int i = 1; i < 4; ++i) cin >> cost[i];

    pair<int,int> t[3];
    for (int i = 0; i < 3; ++i) cin >> t[i].first >> t[i].second;

    int s = min(t[0].first, min(t[1].first, t[2].first));
    int e = max(t[0].second, max(t[1].second, t[2].second));
    int tcost = 0;
    for (int i = s; i <= e; ++i) {
        int c = 0;
        for (int j = 0; j < 3; ++j) {
            if (t[j].first <= i && i < t[j].second) c++;
        }
        tcost += cost[c] * c;
    }
    cout << tcost << endl;
}