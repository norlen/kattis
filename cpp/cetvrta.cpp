#include <iostream>

using namespace std;

pair<int, int> diff(pair<int,int> p0, pair<int,int> p1) {
    return {p0.first - p1.first, p0.second - p1.second};
}

int main() {
    pair<int,int> points[4];
    for (int i = 0; i < 3; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    auto d = diff(points[0], points[1]);
    int x, y;
    if (d.first == 0 || d.second == 0) {
        // straight line.
        auto d1 = diff(points[0], points[2]);
        if (d1.first == 0 || d1.second == 0) {
            x = points[2].first - d.first;
            y = points[2].second - d.second;
        } else {
            x = points[2].first + d.first;
            y = points[2].second + d.second;
        }
    } else {
        d = diff(points[1], points[2]);

        auto d1 = diff(points[1], points[0]);
        if (d1.first == 0 || d1.second == 0) {
            x = points[0].first - d.first;
            y = points[0].second - d.second;
        } else {
            x = points[0].first + d.first;
            y = points[0].second + d.second;
        }
    }
    cout << x << " " << y << endl;
}