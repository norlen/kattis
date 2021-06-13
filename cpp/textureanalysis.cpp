#include <iostream>

using namespace std;

int main() {
    string in;
    int i = 1;
    while (true) {
        cin >> in;
        if (in == "END") break;
        bool even = true;
        int c = 0, d = -1;
        for (int i = 1; i < in.length(); ++i) {
            if (in[i] == '.') {
                c++;
                continue;
            }

            if (d == -1) {
                d = c;
            } else if (d != c) {
                even = false;
                break;
            }
            c = 0;
        }

        cout << i << " " << (even ? "EVEN\n" : "NOT EVEN\n");
        ++i;
    }
}