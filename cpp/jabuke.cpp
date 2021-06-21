#include <iostream>
#include <iomanip>

using namespace std;

int dir(pair<int,int> v0, pair<int,int> v1) {
    return v0.first*v1.second - v0.second*v1.first;
}

int main() {
    pair<int,int> p[3];
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    double area = abs(p[0].first*(p[1].second-p[2].second)+p[1].first*(p[2].second-p[0].second)+p[2].first*(p[0].second-p[1].second)) / 2.0;
    pair<int,int> v0 = { p[1].first - p[0].first, p[1].second - p[0].second };
    pair<int,int> v1 = { p[2].first - p[0].first, p[2].second - p[0].second };
    bool cw = dir(v0, v1) < 0;

    pair<int, pair<int,int>> v[3];
    for (int i = 0; i < 3; ++i) {
        v[i].first = -(p[(i+1)%3].second - p[i].second);
        v[i].second.first = p[(i+1)%3].first - p[i].first;
        v[i].second.second = -(v[i].first*p[i].first + v[i].second.first*p[i].second);
    }

    int n;
    cin >> n;

    int c = 0;
    for (int i = 0; i < n; ++i) {
        pair<int,int> p;
        cin >> p.first >> p.second;

        bool ok = true;
        for (int i = 0; i < 3; ++i) {
            int j = v[i].first*p.first + v[i].second.first*p.second + v[i].second.second;
            bool left = j > 0;
            bool right = j < 0;
            if (!(j == 0 || cw && right || !cw && left)) {
                ok = false;
                break;
            }
        }
        if (ok) c++;
    }

    cout << fixed << setprecision(1) << area << endl << c << endl;
}