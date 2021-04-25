#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double r, c;
    cin >> r >> c;
    double a = r*r*M_PI;
    double b = (r-c)*(r-c)*M_PI;
    cout << fixed << setprecision(8) << b / a * 100 << endl;
}