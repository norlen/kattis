#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int days;
    cin >> days;

    cout << static_cast<int>(ceil(log2f64(static_cast<double>(days)))) + 1 << endl;
}