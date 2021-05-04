#include <iostream>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    if ((p + q)/n % 2 == 0) {
        cout << "paul\n";
    } else {
        cout << "opponent\n";
    }
}