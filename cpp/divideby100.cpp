#include <iostream>

using namespace std;

int main() {
    string n, m;
    cin >> n >> m;

    // If n contains zeroes at the end, we can remove those easily.
    while (n[n.length()-1] == '0' && m[m.length()-1] == '0') {
        n.pop_back();
        m.pop_back();
    }

    int shift = m.length() - 1;
    string out;
    if (shift == 0) {
        out = n;
    } else if (shift < n.length()) {
        out = n.substr(0, n.length()-shift) + "." + n.substr(n.length()-shift);
    } else {
        out = "0.";
        int e = shift - n.length();
        for (int i = 0; i < e; ++i) {
            out.push_back('0');
        }
        out += n;
    }
    cout << out << endl;
}