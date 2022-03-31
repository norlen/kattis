#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    int x;
    int y;
};

double dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double get_angle(double a, double b, double c) {
    double t = b*b + c*c - a*a;
    double bb = 2 * b * c;
    return acos(t/bb);
}

int main() {
    int n;
    cin >> n;

    Point p[3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> p[j].x >> p[j].y;
        }
        // Area = |(Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)) / 2|
        double area = abs(p[0].x*(p[1].y - p[2].y) + p[1].x*(p[2].y - p[0].y) + p[2].x*(p[0].y - p[1].y)) / 2.0;

        string ans;
        if (area > 0.0) {
            double a = dist(p[0], p[1]);
            double b = dist(p[1], p[2]);
            double c = dist(p[2], p[0]);

            // cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

            string tangle = "acute";
            double v[3] = {get_angle(a, b, c), get_angle(b, c, a), get_angle(c, a, b)};
            for (int j = 0; j < 3; ++j) {
                if (abs(v[j] - M_PI_2) <= 0.000001) {
                    tangle = "right";
                    break;
                } else if (v[j] > M_PI_2) {
                    tangle = "obtuse";
                    break;
                }
            }
            // cout << setprecision(10) << "A=" << v[0] << ", B=" << v[1] << ", C=" << v[2] << "   rightv0=" << abs(v[0] - M_PI_2) << " rightv1=" << abs(v[1] - M_PI_2) << " rightv0=" << abs(v[2] - M_PI_2) << endl;

            string ttype = "isosceles";
            if (a != b && a != c && b != c) {
                ttype = "scalene";
            }
            ans = ttype + " " + tangle + " triangle";
        } else {
            ans = "not a triangle";
        }
 	
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
}