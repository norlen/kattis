#include <iostream>

using namespace std;

int main() {
    string ss;
    cin >> ss;

    int i = 0;
    int problems = 0;
    while (i < ss.length()) {
        int dash = -1;
        int s = i;
        while (i < ss.length() && ss[i + 1] != ';') {
            if (ss[i] == '-') {
                dash = i;
            }
            i++;
        }
        int e = i - 1;
        if (dash == -1) {
            problems++;
        } else {
            problems += stoi(ss.substr(dash+1, e)) - stoi(ss.substr(s, dash)) + 1;
        }
        i += 2;
    }

    cout << problems << endl;
}