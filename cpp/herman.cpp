#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double r;
    cin >> r;
    double a = r*r*M_PI;
    double ta = r*r + r*r;
    cout << fixed << setprecision(10) << a << endl << ta << endl;
}