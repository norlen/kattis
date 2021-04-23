#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double s = (a + b + c + d) / 2.0;
    double maxarea = sqrt((s-a)*(s-b)*(s-c)*(s-d));
    cout << fixed << setprecision(10) << maxarea << endl;
}