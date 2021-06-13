#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    string in;
    cout << setprecision(10);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        getline(cin, in); // consume rest of line.

        vector<pair<double,double>> ps;
        double sx = 0, sy = 0;

        for (int i = 0; i < n; ++i) {
            double x, y, angle = 0, tmp;

            stringstream s;
            getline(cin, in);
            s << in;
            s >> x >> y;
            string cmd;
            while (s >> cmd >> tmp) {
                if (cmd == "start") {
                    angle = tmp;
                } else if (cmd == "turn") {
                    angle += tmp;
                } else {
                    // walk.
                    double rads = angle / 180.0 * M_PI;
                    x += cosf64(rads) * tmp;
                    y += sinf64(rads) * tmp;
                }
            }

            sx += x;
            sy += y;
            ps.push_back({x, y});
        }

        sx /= static_cast<double>(ps.size());
        sy /= static_cast<double>(ps.size());

        // Find the worst one.
        double worst = 0.0;
        for (pair<double,double> p : ps) {
            double dx = sx - p.first;
            double dy = sy - p.second;
            double d = sqrt(powf64(dx, 2.0) + powf64(dy, 2.0));
            worst = max(worst, d);
        }

        cout << sx << " " << sy << " " << worst << endl;
    }
}