#include <iostream>

using namespace std;

int main() {
    string in;
    string match = "problem";
    while (getline(cin, in)) {
        int i = 0;
        bool ok = false;
        while (i < in.length() && !ok) {
            if (in[i] == 'P' || in[i] == 'p') {
                int m = 1;
                while (m < match.length() && tolower(in[i+m]) == match[m]) {
                    m++;
                }
                if (m == match.length()) {
                    ok = true;
                    break;
                }
                i += m-1;
            }
            i++;
        }
        cout << (ok ? "yes\n" : "no\n");
    }
}