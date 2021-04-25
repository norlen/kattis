#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    int t;
    cin >> t;
    string in;
    getline(cin, in);

    for (int k = 0; k < t; ++k) {
        string in;
        getline(cin, in);

        list<char> out;
        auto cursor = out.end();
        for (const auto ch : in) {
            if (ch == '<') {
                if (out.size() > 0 && cursor != out.begin()) {
                    cursor = out.erase(--cursor);
                }
            } else if (ch == '[') {
                cursor = out.begin();
            } else if (ch == ']') {
                cursor = out.end();
            } else {
                out.insert(cursor, ch);
            }
        }

        string o;
        for (const auto ch : out) {
            o.push_back(ch);
        }

        cout << o << endl;
    }
}