#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    bool failed = a.length() != b.length();

    bool s = n % 2 == 0;
    for (int i = 0; i < a.length() && !failed; ++i) {
        if ((a[i] == b[i]) != s) {
            failed = true;
        }
    }

    cout << (failed ? "Deletion failed" : "Deletion succeeded") << endl;
}