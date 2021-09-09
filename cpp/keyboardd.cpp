#include <iostream>
#include <set>

using namespace std;

int main() {
    string a, b, sticky;
    getline(cin, a);
    getline(cin, b);
    set<char> s;

    int i = 0, j = 0;
    while (i < a.length()) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (s.count(b[j]) == 0) {
                s.insert(b[j]);
                sticky.push_back(b[j]);
            }
            j++; // If it's sticky, move forward until it "catches" up.
        }
    }
    // If it's the very last character.
    if (j != b.length()) {
        if (s.count(b[j]) == 0) {
            s.insert(b[j]);
            sticky.push_back(b[j]);
        }
    };

    cout << sticky << endl;
}
