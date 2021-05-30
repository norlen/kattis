#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<pair<int, pair<int, int>>> circles;
    vector<pair<pair<int,int>, pair<int,int>>> rects;
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        if (t == "rectangle") {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            rects.push_back({{x0, y0}, {x1, y1}});
        } else {
            int r, x, y;
            cin >> x >> y >> r;
            circles.push_back({r, {x, y}});
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        int hits = 0;
        for (auto& r : rects) {
            int x0 = r.first.first;
            int y0 = r.first.second;
            int x1 = r.second.first;
            int y1 = r.second.second;
            if (x >= x0 && x <= x1 && y >= y0 && y <= y1) hits++;
        }
        for (auto& c : circles) {
            int dx = x - c.second.first;
            int dy = y - c.second.second;
            int r = c.first;
            if (dx*dx + dy*dy <= r*r) hits++;
        }
        cout << hits << endl;
    }
}