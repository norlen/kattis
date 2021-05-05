#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double d;
    cin >> d;
    cout << fixed << setprecision(10) << powf64(d, 1.0/d) << endl;
}