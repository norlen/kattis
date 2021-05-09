#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ml = b - a - 1;
    int mr = c - b - 1;
    cout << max(ml, mr) << endl;
}