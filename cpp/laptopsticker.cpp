#include <iostream>

using namespace std;

int main() {
    int cw, ch, sw, sh;
    cin >> cw >> ch >> sw >> sh;
    if (sw+1 >= cw || sh+1 >= ch) cout << "0\n";
    else cout << "1\n";
}