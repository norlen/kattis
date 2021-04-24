#include <iostream>

using namespace std;

int main() {
    int e, f, c;
    cin >> e >> f >> c;

    int has = e + f;
    int count = 0;
    while (has >= c) {
        int gain = has / c;
        has = has % c + gain;
        count += gain;
    }
    cout << count << endl;
}