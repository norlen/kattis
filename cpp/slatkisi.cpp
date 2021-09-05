#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double c;
    int k;
    cin >> c >> k;

    double divis = powf64(10.0, k);
    cout << static_cast<int>(round(c / divis) * divis) << endl;
}
