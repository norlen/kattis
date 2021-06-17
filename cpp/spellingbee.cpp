#include <iostream>
#include <set>

using namespace std;

int main() {
    string letters, curr;
    int n;
    cin >> letters >> n;
    char center = letters[0];

    set<char> s;
    for (auto ch : letters) {
        s.insert(ch);
    }

    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (curr.length() < 4) continue;

        bool nope = false, has_center = false;
        for (auto ch : curr) {
            if (ch == center) has_center = true;
            if (s.count(ch) == 0) {
                nope = true;
                break;
            }
        }

        if (!nope && has_center) {
            cout << curr << endl;
        }
    }
}