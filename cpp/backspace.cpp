#include <iostream>

using namespace std;

int main() {
    string in, out;
    cin >> in;

    for (const auto ch : in) {
        if (ch == '<' && out.length() > 0) {
            out.pop_back();
        } else {
            out.push_back(ch);
        }
    }
    if (out.length() > 0)
        cout << out << endl;
}