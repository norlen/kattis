#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    unordered_map<char, int> s;
    for (auto ch : a) {
        if (s.count(ch) > 0) {
            s[ch] += 1;
        } else {
            s.insert({ch, 1});
        }
    }

    int j = 0; // current character we're searching for in password.
    bool ok = true;
    for (int i = 0; i < b.length(); ++i) {
        char curr = b[i], hidden = a[j];
        if (curr == hidden) {
            j++;
            s[curr] -= 1;
            if (j == a.length()) {
                // we've checked entire password string, no point in going on.
                break;
            }
        } else if (s.count(curr) > 0 && s[curr] > 0) {
            // Current exists in the set, which means the string does not pass.
            ok = false;
            break;
        }
    }

    // Another failure case is if we haven't found all characters in the password.
    bool pass = ok && j == a.length();

    cout << (pass ? "PASS\n" : "FAIL\n");
}
