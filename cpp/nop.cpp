#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;

    int addr = 0;
    int nops = 0;
    for (auto ch : in) {
        int n = 0;
        if (ch >= 'A' && ch <= 'Z') {
            n = (4 - addr % 4) % 4;
            nops += n;
        }
        addr = addr + 1 + n;
    }

    cout << nops << endl;
}