#include <iostream>

using namespace std;

int main() {
    // Form of: “:)”, “;)”, “:-)”, or “;-)”.
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == ':' || s[i] == ';') {
            if (s[i+1] == ')') {
                cout << i << endl;
                i += 1;
            } else if (s[i+1] == '-' && i < s.size()-2 && s[i+2] == ')') {
                cout << i << endl;
                i += 2;
            }
        }
    }
}
