#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int cw = (b - a + 360) % 360;
    int ccw = (a - b + 360) % 360;
    cout << (ccw < cw ? -ccw : cw) << endl;
}