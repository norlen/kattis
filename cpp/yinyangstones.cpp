#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;
    int n = 0;
    for (auto ch : in) {
        if (ch == 'B') n++;
        else n--;
    }
    cout << (n == 0 ? "1\n" : "0\n") << endl;
}