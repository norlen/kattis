#include <iostream>
#include <array>

using namespace std;
using ll = long long;

int main() {
    constexpr array<int, 8> regs = {2, 3, 5, 7, 11, 13, 17, 19};
    ll inc_to_reg = 1, increments = 0, current;
    for (int i = 0; i < regs.size(); ++i) {
        cin >> current;
        increments -= inc_to_reg * current;
        inc_to_reg *= regs[i];
    }
    increments += inc_to_reg;

    cout << (increments - 1) << endl;
}