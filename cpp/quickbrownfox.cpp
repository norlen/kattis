#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string in;
    getline(cin, in); // consume rest of line.

    for (int i = 0; i < n; ++i) {
        getline(cin, in);

        int missing[26] = {0};
        int count = 0;

        for (auto ch : in) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = tolower(ch);
            }
            if (ch >= 'a' && ch <= 'z') {
                if (missing[ch - 'a'] == 0) count++;
                missing[ch - 'a'] += 1;
            }
        }

        if (count < 26) {
            cout << "missing ";
            for (int i = 0; i < 26; ++i) {
                if (missing[i] == 0) {
                    cout << (char)(i + 'a');
                }
            }
            cout << endl;
        } else {
            cout << "pangram\n";
        }
    }
}