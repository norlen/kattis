#include <iostream>

using namespace std;

int main() {
    string ss;
    cin >> ss;

    int w = 0;
    int l = 0;
    int u = 0;
    int s = 0;
    for (const auto ch : ss) {
        if (ch >= 'a' && ch <= 'z') l++;
        else if (ch >= 'A' && ch <= 'Z') u++;
        else if (ch == '_') w++;
        else s++;
    }

    // ratios of whitespace characters, lowercase letters, uppercase letters, and symbols (in that order)
    double len = static_cast<double>(ss.length());
    cout << static_cast<double>(w) / len << endl;
    cout << static_cast<double>(l) / len << endl;
    cout << static_cast<double>(u) / len << endl;
    cout << static_cast<double>(s) / len << endl;
}