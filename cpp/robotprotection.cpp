#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int,int>> jarvismarch(const vector<pair<int,int>>& points) {
    // Find leftmost point.
    pair<int,int> first_point = { INT32_MAX, 0 };
    size_t first_point_idx = 0;
    for (int i = 0; i < points.size(); ++i) {
        if (points[i].first < first_point.first) {
            first_point_idx = i;
            first_point = points[i];
        }
    }

    vector<pair<int,int>> out;
    out.push_back(first_point);

    size_t l = first_point_idx;
    while (true) {
        size_t q = (l + 1) % points.size();
        for (int i = 0; i < points.size(); ++i) {
            if (i == l) continue;

            // From l to i to q, if this is a right turn we replace q with i.
            // If they are co-linear we replace q with i if the distance l-i is greater than l-q.
            pair<int,int> v1 = { points[q].first - points[l].first, points[q].second - points[l].second };
            pair<int,int> v2 = { points[i].first - points[l].first, points[i].second - points[l].second };
            int cross = v2.first * v1.second - v2.second * v1.first;
            // If the cross-product is > 0 it's a right turn, if it's zero they are co-linear.
            if (cross > 0) {
                q = i;
            } else if (cross == 0) {
                double d_v1 = powf64(v1.first, 2.0) + powf64(v1.second, 2.0);
                double d_v2 = powf64(v2.first, 2.0) + powf64(v2.second, 2.0);
                if (d_v2 > d_v1) {
                    q = i;
                }
            }
        }

        l = q;
        if (l == first_point_idx) {
            break;
        }
        out.push_back(points[q]);
    }

    return out;
}

int main() {
    cout << setprecision(2) << fixed;
    
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<pair<int,int>> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        auto hull = jarvismarch(points);

        double a = 0.0, b = 0.0;
        for (int i = 0; i < hull.size(); ++i) {
            int j = (i+1) % hull.size();
            a += hull[i].first * hull[j].second;
            b += hull[j].first * hull[i].second;
        }

        cout << abs(1.0/2.0 * (a - b)) << endl;
    }
}