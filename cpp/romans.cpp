#include <iostream>

using namespace std;

int main() {
    double in;
    cin >> in;
    cout << (int)(in * 1000.0 * 5280.0 / 4854.0 + 0.5) << endl;
}